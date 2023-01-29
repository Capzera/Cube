#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) {
    int a, b;
    cin >> a >> b;
    a += b;
    cout << a + b * b<< endl;
}

Widget::~Widget() {}
