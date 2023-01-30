#include "map.h"

QVector<QVector<int>> di = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

MAP::MAP(QWidget *parent) : QWidget(parent) {
    setFixedSize(850, 650);
    block_pos = QVector<QVector<QVector<BLOCK*>>> (ROW, QVector<QVector<BLOCK*>> (COL, QVector<BLOCK*> (0)));
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
       //qDebug("%s\n", buffer.back());
    }
    COL = buffer[0].toInt();
    ROW = buffer[1].toInt();
    mapInit();
}

void MAP::blockPosInit(int level)
{
    QDir *folder = new QDir;
    bool folderCheck = folder->exists("./level");
    if (!folderCheck) {
        folder->mkpath("./level");
    }
    QString fileName = "./level/level" + QString::number(level) + "-" + QString::number(level) + ".txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    while (!file.atEnd()){
        QByteArray buf = file.readLine();
        QString oneLine(buf);
        //qDebug("%s\n", oneLine);
        QVector<int> bl(5);
        QString tmp;
        for(int i=0, j=0, cnt=0; i<oneLine.size(); ++i){
            if(oneLine[i] == ' '){
                tmp = oneLine.mid(j, i-j);
                bl[cnt++] = tmp.toInt();
                tmp.clear();
            }
        }
        block_pos[bl[3]][bl[4]].push_back(new BLOCK(bl[0], bl[1], bl[2], bl[3], bl[4]));
    }
}

void MAP::mapInit() {
    PLAYER = new BLOCK(1,0,0,0,0);
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
    draw_player_block(PLAYER);
}

void MAP::draw_puzzle_block(BLOCK *bl) {
    QPainter paint(this);
    if (bl->getColor() == BLOCK_COLOR::RED) {
        paint.setPen(QPen(Qt::red, 3, Qt::SolidLine));
    }
    if (bl->getColor() == BLOCK_COLOR::BLUE) {
        paint.setPen(QPen(Qt::blue, 3, Qt::SolidLine));
    }
    if (bl->getColor() == BLOCK_COLOR::YELLOW) {
        paint.setPen(QPen(Qt::yellow, 3, Qt::SolidLine));
    }
    if (bl->getColor() == BLOCK_COLOR::GREEN) {
        paint.setPen(QPen(Qt::green, 3, Qt::SolidLine));
    }
    bool big;
    int direct;
    switch (bl->getBlockState()) {
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
    int pos_x = bl->getPos().x(), pos_y = bl->getPos().y();
    int x = locate_x[pos_x][pos_y], y = locate_y[pos_x][pos_y];
    if (big) {
        length = B_wide * 3 / 4;
        x += B_wide / 8;
        y += B_wide / 8;
    }
    else {
        length = B_wide / 2;
        x += B_wide / 4;
        y += B_wide / 4;
    }
    for (int i = 1; i <= 4; i++) {
        if (i == direct) continue;
        if (i == 1) paint.drawLine(QPoint(x, y), QPoint(x + length, y));
        if (i == 2) paint.drawLine(QPoint(x, y + length), QPoint(x + length, y + length));
        if (i == 3) paint.drawLine(QPoint(x, y), QPoint(x, y + length));
        if (i == 4) paint.drawLine(QPoint(x + length, y), QPoint(x + length, y + length));
    }
}

void MAP::draw_player_block(BLOCK *bl) {
    int radius = B_wide * 2 / 10, split = B_wide * 4 / 10;
    QPainter paint(this);
    paint.setPen(QPen(Qt::black, radius, Qt::SolidLine));
    int pos_x = bl->getPos().x(), pos_y = bl->getPos().y();
    int x = locate_x[pos_x][pos_y], y = locate_y[pos_x][pos_y];
    paint.drawEllipse(x + split, y + split, radius, radius);
}

void MAP::operat(int d) {
    int x = PLAYER->getPos().x(), y = PLAYER->getPos().y();
    int mx = x + di[d][0], my = y + di[d][1];
    if (mx < 0 || mx == ROW || my < 0 || my == COL) return;
    PLAYER->move(mx, my);
}
