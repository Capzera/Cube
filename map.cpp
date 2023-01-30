#include "map.h"

MAP::MAP(QWidget *parent) : QWidget(parent) {
    setFixedSize(850, 650);
    mapInit();
}

void MAP::mapInit() {
    locate_x = locate_y = QVector<QVector<int>>(ROW, QVector<int>(COL));
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            locate_x[i][j] = B_wide * j + 25;
            locate_y[i][j] = B_wide * i + 25;
        }
    }
}

void MAP::paintEvent(QPaintEvent *event){
    draw_frame();
    draw_block();
    update();
}

void MAP::draw_frame() {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));//设置画笔
    painter.drawRect(25, 25, 800, 600);//画游戏区域外矩阵
}

void MAP::draw_block() {
    QPainter paint(this);
    paint.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
    //设置画笔颜色为red，粗细为2，虚线
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            paint.drawEllipse(locate_x[i][j], locate_y[i][j], B_wide, B_wide);//临时画圆占位用于测试
        }
    }
}
