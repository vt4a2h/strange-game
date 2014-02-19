#include "basicitem.h"

namespace graphics_item {

    BasicItem::BasicItem(QSizeF size, QGraphicsItem *parent)
        : QGraphicsObject(parent)
        , m_Size(size)
    {
    }

    QRectF BasicItem::boundingRect() const
    {
        QPointF leftTop(-m_Size.width() / 2 - MARGIN, -m_Size.height() / 2 - MARGIN);
        QSizeF size(m_Size.width() + MARGIN, m_Size.height() + MARGIN);

        return QRectF(leftTop, size);
    }

    void BasicItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        Q_UNUSED(option)
        Q_UNUSED(widget)

        painter->setBrush(Qt::black);
        painter->drawRect(QRectF(QPointF(-m_Size.width() / 2, -m_Size.height() / 2), m_Size));
    }

    void BasicItem::moveLeft()
    {
        moveBy(-m_Size.width(), 0);
    }

    void BasicItem::moveRight()
    {
        moveBy(m_Size.width(), 0);
    }

    void BasicItem::moveUp()
    {
        moveBy(0, -m_Size.height());
    }

    void BasicItem::moveDown()
    {
        moveBy(0, m_Size.height());
    }

    float BasicItem::height() const
    {
        return m_Size.height();
    }

    float BasicItem::width() const
    {
        return m_Size.width();
    }

} // namespace graphics_item
