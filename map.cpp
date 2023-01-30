#include "map.h"

MAP::MAP(QWidget *parent) : QWidget(parent) {
    setFixedSize(850, 650);
}

void MAP::getLevel(int level) {
    QDir *folder = new QDir;
    bool folderCheck = folder->exists("./level");
    if (!folderCheck) {
        folder->mkpath("./level");
    }
    QString fileName = "./level/level" + QString::number(level) + ".txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QVector<QString> buffer;
    while (!file.atEnd()){
       QByteArray buf = file.readLine();
       buffer.push_back(buf);
    }
    COL = buffer[0].toInt();
    ROW = buffer[1].toInt();
    mapInit();
}

void MAP::mapInit() {
    B_wide = 800 / COL;
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
}

void MAP::draw_puzzle_block(BLOCK bl) {
    QPainter paint(this);
    if (bl.getColor() == BLOCK_COLOR::RED) {
        paint.setPen(QPen(Qt::red, 2, Qt::SolidLine));
    }
    if (bl.getColor() == BLOCK_COLOR::BLUE) {
        paint.setPen(QPen(Qt::blue, 2, Qt::SolidLine));
    }
    if (bl.getColor() == BLOCK_COLOR::YELLOW) {
        paint.setPen(QPen(Qt::yellow, 2, Qt::SolidLine));
    }
    if (bl.getColor() == BLOCK_COLOR::GREEN) {
        paint.setPen(QPen(Qt::green, 2, Qt::SolidLine));
    }
    bool big;
    int direct;
    switch (bl.getBlockState()) {
        case BLOCK_STATE::SMALL_UP :
            direct = 1;
            big = 0;
        break;
        case BLOCK_STATE::SMALL_DOWN :
            direct = 2;
            big = 0;
        break;
        case BLOCK_STATE::SMALL_LEFT :
            direct = 3;
            big = 0;
        break;
        case BLOCK_STATE::SMALL_RIGHT :
            direct = 4;
            big = 0;
        break;
        case BLOCK_STATE::BIG_UP :
            direct = 1;
            big = 1;
        break;
        case BLOCK_STATE::BIG_DOWN :
            direct = 2;
            big = 1;
        break;
        case BLOCK_STATE::BIG_LEFT :
            direct = 3;
            big = 1;
        break;
        case BLOCK_STATE::BIG_RIGHT :
            direct = 4;
            big = 1;
        break;
    }
    int length;
    if (big) length = B_wide * 3 / 4;
    else length = B_wide / 2;
    int x = bl.getPos().x() + B_wide / 8, y = bl.getPos().y() + B_wide / 8;
    for (int i = 1; i <= 4; i++) {
        if (i == direct) continue;
        if (i == 1) paint.drawLine(QPoint(x, y), QPoint(x + length, y));
        if (i == 2) paint.drawLine(QPoint(x, y + length), QPoint(x + length, y + length));
        if (i == 3) paint.drawLine(QPoint(x, y), QPoint(x, y + length));
        if (i == 4) paint.drawLine(QPoint(x + length, y), QPoint(x + length, y + length));
    }
}
