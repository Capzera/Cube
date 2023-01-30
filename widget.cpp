#include "widget.h"

Widget::Widget(QWidget *parent): QWidget(parent) {
    Init();
}

void Widget::Init() {
    this->setWindowTitle("Cube");
    this->setFixedSize(1150,650);
    btn1 = new QPushButton("上一关", this);
    btn2 = new QPushButton("下一关", this);
    btn3 = new QPushButton("重来", this);
    le1 = new QLineEdit("第1关", this);
    le1->setReadOnly(1);
    M = new MAP(this);
    M->getLevel(LEVEL);
    le1->setAlignment(Qt::AlignHCenter);
    btn1->setGeometry(855, 135, 80, 40);
    le1->setGeometry(940, 137, 70, 35);
    btn2->setGeometry(1015, 135, 80, 40);
    btn3->setGeometry(895, 195, 160, 40);//设置控件几何坐标
    connect(btn1, SIGNAL(clicked(bool)), this, SLOT(lastLevel()));//槽函数建立
    connect(btn2, SIGNAL(clicked(bool)), this, SLOT(nextLevel()));
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_W :
            M->operat(1);
            break;
        case Qt::Key_S :
            M->operat(2);
            break;
        case Qt::Key_A :
            M->operat(3);
            break;
        case Qt::Key_D :
            M->operat(4);
            break;
    }
}

void Widget::lastLevel() {
    if (LEVEL == 1) return;//防止第一关点"上一关"
    LEVEL--;
    le1->setText("第" + QString::number(LEVEL) + "关");
    M->getLevel(LEVEL);
}

void Widget::nextLevel() {
    if (LEVEL == MAX_LEVEL) return;//防止最后一关点"下一关"
    LEVEL++;
    le1->setText("第" + QString::number(LEVEL) + "关");
    M->getLevel(LEVEL);
}

Widget::~Widget() {}
