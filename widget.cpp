#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) {
    this->setWindowTitle("Cube");
    this->setFixedSize(1150,650);

}

void Widget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 4, Qt::SolidLine));
    painter.drawRect(25, 25, 800, 600);
}

Widget::~Widget() {}
