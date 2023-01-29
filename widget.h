#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QPen>

class Widget : public QWidget {
    Q_OBJECT
public:
    Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~Widget();
};

#endif // WIDGET_H
