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
    //M->goReset(Reset);
    le1->setAlignment(Qt::AlignHCenter);
    btn1->setGeometry(855, 135, 80, 40);
    le1->setGeometry(940, 137, 70, 35);
    btn2->setGeometry(1015, 135, 80, 40);
    btn3->setGeometry(895, 195, 160, 40);//设置控件几何坐标
    connect(btn1, SIGNAL(clicked(bool)), this, SLOT(lastLevel()));//槽函数建立
    connect(btn2, SIGNAL(clicked(bool)), this, SLOT(nextLevel()));
    connect(btn3, SIGNAL(clicked(bool)), this, SLOT(Reset()));
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_W :
           if(M->operat(1)){
               if (LEVEL == MAX_LEVEL) {//防止最后一关点"下一关"
                   QMessageBox::information(this, "提示信息", "这是最后一关了喔");
                   return;
               }
               LEVEL++;
               le1->setText("第" + QString::number(LEVEL) + "关");
               M->getLevel(LEVEL);
           }
            break;
        case Qt::Key_S :
        if(M->operat(2)){
            if (LEVEL == MAX_LEVEL) {//防止最后一关点"下一关"
                QMessageBox::information(this, "提示信息", "这是最后一关了喔");
                return;
            }
            LEVEL++;
            le1->setText("第" + QString::number(LEVEL) + "关");
            M->getLevel(LEVEL);
        }
            break;
        case Qt::Key_A :
        if(M->operat(3)){
            if (LEVEL == MAX_LEVEL) {//防止最后一关点"下一关"
                QMessageBox::information(this, "提示信息", "这是最后一关了喔");
                return;
            }
            LEVEL++;
            le1->setText("第" + QString::number(LEVEL) + "关");
            M->getLevel(LEVEL);
        }
            break;
        case Qt::Key_D :
        if(M->operat(4)){
            if (LEVEL == MAX_LEVEL) {//防止最后一关点"下一关"
                QMessageBox::information(this, "提示信息", "这是最后一关了喔");
                return;
            }
            LEVEL++;
            le1->setText("第" + QString::number(LEVEL) + "关");
            M->getLevel(LEVEL);
        }
            break;
    }
}

void Widget::lastLevel() {
    if (LEVEL == 1) {//防止第一关点"上一关"
        QMessageBox::information(this, "提示信息", "这已经是最简单的一关啦");
        return;
    }
    LEVEL--;
    le1->setText("第" + QString::number(LEVEL) + "关");
    M->getLevel(LEVEL);
}

void Widget::nextLevel() {
    if (LEVEL == MAX_LEVEL) {//防止最后一关点"下一关"
        QMessageBox::information(this, "提示信息", "这是最后一关了喔");
        return;
    }
    LEVEL++;
    le1->setText("第" + QString::number(LEVEL) + "关");
    M->getLevel(LEVEL);
}

void Widget::Reset() {
    M->getLevel(LEVEL);
}

Widget::~Widget() {}
