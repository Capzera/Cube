#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}

Widget::~Widget() {}
