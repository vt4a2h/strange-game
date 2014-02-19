#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <memory>

namespace Ui {
    class MainWindow;
}

namespace graphics_item {
    class BasicItem;
    class Grid;
}

using Scene = std::unique_ptr<QGraphicsScene>;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:    
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject *o, QEvent *ev) override;

    void newGame();

signals:
    void youLose();

private:
    enum GameStatus{InGame, Win, Lose};

    void playerLose();
    void setupElements();
    void connectElements();
    void itemToStart();

    static constexpr size_t CELL_COUNT_H = 30;
    static constexpr size_t CELL_COUNT_V = 30;
    static constexpr float  CELL_HEIGHT  = 20;
    static constexpr float  CELL_WIDTH   = 20;

    Ui::MainWindow *ui;

    Scene m_Scene;
    QGraphicsTextItem *m_TextMessage;
    graphics_item::BasicItem *m_Item;
    graphics_item::Grid *m_Grid;

    GameStatus m_GameStatus;
};

#endif // MAINWINDOW_H
