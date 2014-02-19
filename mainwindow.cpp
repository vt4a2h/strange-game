#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "grid.h"
#include "basicitem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_Scene(new QGraphicsScene())
    , m_TextMessage(new QGraphicsTextItem())
    , m_Item(new graphics_item::BasicItem({CELL_WIDTH, CELL_HEIGHT}))
    , m_Grid(new graphics_item::Grid(CELL_COUNT_H, CELL_COUNT_V, {CELL_WIDTH, CELL_HEIGHT}))
{
    ui->setupUi(this);

    ui->gv_Main->setScene(m_Scene.get());
    ui->gv_Main->installEventFilter(this);

    m_Scene->addItem(m_Grid);
    m_Scene->addItem(m_Item);
    m_Scene->addItem(m_TextMessage);

    setupElements();
    connectElements();

    newGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::eventFilter(QObject *o, QEvent *ev)
{
    if (o == ui->gv_Main) {
        if (ev->type() == QEvent::KeyPress) {
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(ev);

            if (m_GameStatus == InGame) {
                switch (keyEvent->key()) {
                case Qt::Key_Left:
                    m_Item->moveLeft();
                    break;
                case Qt::Key_Right:
                    m_Item->moveRight();
                    break;
                case Qt::Key_Up:
                    m_Item->moveUp();
                    break;
                case Qt::Key_Down:
                    m_Item->moveDown();
                    break;
                }
            } else if (m_GameStatus == Lose && keyEvent->key() == Qt::Key_R){
                newGame();
            }

            return true;
        }
    }

    return QMainWindow::eventFilter(o, ev);
}

void MainWindow::newGame()
{
    m_GameStatus = InGame;
    m_TextMessage->hide();
    itemToStart();
}

void MainWindow::playerLose()
{
    m_TextMessage->show();
    m_GameStatus = Lose;
}

void MainWindow::setupElements()
{
    QPointF messagePos(m_Grid->width() / 2 + 10, - m_Grid->height() / 2);
    m_TextMessage->setPlainText(tr("Вы проиграли!\n\nНажмите \"r\" для начала новой игры."));
    m_TextMessage->setPos(messagePos);
}

void MainWindow::connectElements()
{
    connect(m_Item, &QGraphicsObject::xChanged, [this](){
        auto r = m_Grid->boundingRect();
        if (m_Item->x() < r.left() || m_Item->x() > r.right()) emit youLose();
    });
    connect(m_Item, &QGraphicsObject::yChanged, [this](){
        auto r = m_Grid->boundingRect();
        if (m_Item->y() < r.top() || m_Item->y() > r.bottom()) emit youLose();
    });

    connect(this, &MainWindow::youLose, this, &MainWindow::playerLose);
}

void MainWindow::itemToStart()
{
    QPointF itemPos(-m_Grid->width() / 2 + m_Item->width() / 2, m_Grid->height() / 2 - m_Item->height() / 2);
    m_Item->setPos(itemPos);
}
