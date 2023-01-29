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
    locate_x = locate_y = QVector<QVector<int>> (ROW, QVector<int>(COL));//初始化像素坐标
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            //游戏区划分为20*15的区域，每个区域格占40*40的像素，游戏画布离画面边框25像素宽
            locate_x[i][j] = B_wide * j + 25;
            locate_y[i][j] = B_wide * i + 25;//储存20*15个方格的每个方格左上角像素坐标
        }
    }
    le1 = new QLineEdit("第1关", this);
    le1->setReadOnly(1);
    le1->setAlignment(Qt::AlignHCenter);
    btn1->setGeometry(855, 135, 80, 40);
    le1->setGeometry(940, 135, 70, 40);
    btn2->setGeometry(1015, 135, 80, 40);
    btn3->setGeometry(895, 195, 160, 40);//设置控件几何坐标
    connect(btn1, SIGNAL(clicked(bool)), this, SLOT(lastLevel()));//槽函数建立
    connect(btn2, SIGNAL(clicked(bool)), this, SLOT(nextLevel()));
}

void Widget::paintEvent(QPaintEvent *event){
    draw_frame();
    draw_block();
    update();
}

void Widget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_W :
            operat(1);
            break;
        case Qt::Key_S :
            operat(2);
            break;
        case Qt::Key_A :
            operat(3);
            break;
        case Qt::Key_D :
            operat(4);
            break;
    }
}

void Widget::lastLevel() {
    if (LEVEL == 1) return;//防止第一关点"上一关"
    LEVEL--;
    le1->setText("第" + QString::number(LEVEL) + "关");
}

void Widget::nextLevel() {
    if (LEVEL == MAX_LEVEL) return;//防止最后一关点"下一关"
    LEVEL++;
    le1->setText("第" + QString::number(LEVEL) + "关");
}

void Widget::draw_frame() {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));//设置画笔
    painter.drawRect(25, 25, 800, 600);//画游戏区域外矩阵
}

void Widget::draw_block() {
    QPainter paint(this);
    paint.setPen(QPen(Qt::red, 2, Qt::DashLine));
    //设置画笔颜色为red，粗细为2，虚线
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            paint.drawEllipse(locate_x[i][j], locate_y[i][j], B_wide, B_wide);//临时画圆占位用于测试
        }
    }
}

void Widget::operat(int op) {
    if (op == 1) {
        qDebug() << "按下了W";
    }
    if (op == 2) {
        qDebug() << "按下了S";
    }
    if (op == 3) {
        qDebug() << "按下了A";
    }
    if (op == 4) {
        qDebug() << "按下了D";
    }
}

Widget::~Widget() {}
