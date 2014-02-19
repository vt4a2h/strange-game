#ifndef GRAPHICS_ITEM_BASICITEM_H
#define GRAPHICS_ITEM_BASICITEM_H

#include <QGraphicsObject>
#include <QPainter>
#include <QDebug>

namespace graphics_item {

    class BasicItem : public QGraphicsObject
    {
        Q_OBJECT
    public:
        explicit BasicItem(QSizeF size, QGraphicsItem *parent = 0);

        QRectF boundingRect() const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        float height() const;
        float width() const;

    private:
        static constexpr float MARGIN = 2;

        QSizeF m_Size;
    };

} // namespace graphics_item

#endif // GRAPHICS_ITEM_BASICITEM_H
