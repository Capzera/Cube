#include "map.h"

QVector<QVector<int>> di = {{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}};
QMap<int, int> um = {{1, 2}, {2, 1}, {3, 4}, {4, 3}};

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
       //qDebug("%s\n", buffer.back());
    }
    COL = buffer[0].toInt();
    ROW = buffer[1].toInt();
    mapInit();
    blockPosInit(level);
}

void MAP::blockPosInit(int level)
{
    QString fileName = "./level/level" + QString::number(level) + "-1" + ".txt";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    blockPos.clear();
    barrier.clear();
    while (!file.atEnd()){
        QByteArray buf = file.readLine();
        QString oneLine(buf), tmp;
        QVector<int> bl;
        bool flag = false;
        for(auto& c : oneLine){
            char x = c.toLatin1();
            if(x == '!'){
                flag = true;
                continue;
            }
            if(x == '%') {
                bl.push_back(tmp.toInt());
                tmp.clear();
            }
            else tmp += x;
        }
        if(!flag)
            blockPos.push_back(new BLOCK(bl[0], bl[1], bl[2], bl[3], bl[4], bl[5]));
        if(flag)
            barrier.push_back(new BARRIER(bl[0], bl[1]));
    }
}

void MAP::mapInit() {
    PLAYER = new BLOCK(0,0,1,0,0,0);
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
    draw_barrier();
    update();
}

void MAP::draw_barrier()
{
    QPainter paint(this);
    paint.setPen(QPen(Qt::black, 4, Qt::SolidLine));
    for(int i=0; i<barrier.size(); ++i) {
        int pos_x = barrier[i]->getPos().x(), pos_y = barrier[i]->getPos().y();
        int x = locate_x[pos_x][pos_y], y = locate_y[pos_x][pos_y];
        paint.fillRect(QRect(x, y, B_wide, B_wide), Qt::SolidPattern);
    }
}

void MAP::draw_frame() {
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3, Qt::SolidLine));//设置画笔
    painter.drawRect(25, 25, 800, 600);//画游戏区域外矩阵
}

void MAP::draw_block() {
    draw_player_block(PLAYER);
    for (BLOCK *bp : blockPos) {
        if (bp->getState() == GRID_STATE::FINISH) {
            draw_finish_block(bp);
        }
        if (bp->getState() == GRID_STATE::BLOCKS) {
            draw_puzzle_block(bp);
        }
    }
}

void MAP::draw_puzzle_block(BLOCK *bl) {
    QPainter paint(this);
    if (bl->getColor() == BLOCK_COLOR::RED) {
        paint.setPen(QPen(Qt::red, 5, Qt::SolidLine, Qt::RoundCap));
    }
    if (bl->getColor() == BLOCK_COLOR::BLUE) {
        paint.setPen(QPen(Qt::blue, 5, Qt::SolidLine, Qt::RoundCap));
    }
    if (bl->getColor() == BLOCK_COLOR::YELLOW) {
        paint.setPen(QPen(Qt::yellow, 5, Qt::SolidLine, Qt::RoundCap));
    }
    if (bl->getColor() == BLOCK_COLOR::GREEN) {
        paint.setPen(QPen(Qt::green, 5, Qt::SolidLine, Qt::RoundCap));
    }
    bool big = bl->getSize() == BLOCK_SIZE::BIG;
    int direct;
    switch (bl->getDirection()) {
        case BLOCK_DIRECTION::UP :
            direct = 1;
        break;
        case BLOCK_DIRECTION::DOWN :
            direct = 2;
        break;
        case BLOCK_DIRECTION::LEFT :
            direct = 3;
        break;
        case BLOCK_DIRECTION::RIGHT :
            direct = 4;
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
    int radius = B_wide / 5, split = B_wide * 2 / 5;
    QPainter paint(this);
    paint.setPen(QPen(Qt::black, radius, Qt::SolidLine));
    int pos_x = bl->getPos().x(), pos_y = bl->getPos().y();
    int x = locate_x[pos_x][pos_y], y = locate_y[pos_x][pos_y];
    paint.drawEllipse(x + split, y + split, radius, radius);
}

void MAP::draw_finish_block(BLOCK *bl) {
    QPainter paint(this);
    switch(bl->getColor()) {
        case BLOCK_COLOR::RED :
            paint.setPen(QPen(Qt::red, 4, Qt::SolidLine));
        break;
        case BLOCK_COLOR::YELLOW :
            paint.setPen(QPen(Qt::yellow, 4, Qt::SolidLine));
        break;
        case BLOCK_COLOR::BLUE :
            paint.setPen(QPen(Qt::blue, 4, Qt::SolidLine));
        break;
        case BLOCK_COLOR::GREEN :
            paint.setPen(QPen(Qt::green, 4, Qt::SolidLine));
        break;
        default:
            paint.setPen(QPen(Qt::white, 5, Qt::SolidLine));
        break;
    }

    int pos_x = bl->getPos().x(), pos_y = bl->getPos().y();
    int x = locate_x[pos_x][pos_y], y = locate_y[pos_x][pos_y];
    int radius = B_wide * 3 / 4, split = B_wide / 8;
    paint.drawEllipse(x + split, y + split, radius, radius);
    radius = B_wide / 2, split = B_wide / 4;
    paint.drawEllipse(x + split, y + split, radius, radius);
    radius = B_wide / 4, split = B_wide * 3 / 8;
    paint.drawEllipse(x + split, y + split, radius, radius);
}

void MAP::operat(int d) {
    int x = PLAYER->getPos().x(), y = PLAYER->getPos().y();
    int mx = x + di[d][0], my = y + di[d][1];
    int mmx = mx + di[d][0], mmy = my + di[d][1];
    if (mx < 0 || mx == ROW || my < 0 || my == COL) return;
    QVector<BLOCK*> cur = targetGrid(x, y), target = targetGrid(mx, my);
    if (cur.empty()) {//当前格无方块
        if (target.empty()) {
            PLAYER->move(mx, my);
        }
        if (target.size() == 1) {
            if (canInto(target[0], d)) {
                PLAYER->move(mx, my);
            }
            else {
                if (mmx < 0 || mmx == ROW || mmy < 0 || mmy == COL) return;
                QVector<BLOCK*> target2 = targetGrid(mmx, mmy);
                if (target2.size() && target2[0]->getSize() == target[0]->getSize()) return;
                if (target2.size() && target[0]->isSmall() && !canInto(target2[0], d)) return;
                if (target2.size() && target[0]->isBig() && target[0]->getDirection() != d) return;
                PLAYER->move(mx, my);
                target[0]->move(mmx, mmy);
            }
        }
        if (target.size() == 2) {
            if (canInto(target[0], d) && canInto(target[1], d)) {
                PLAYER->move(mx, my);
            }
            else {
                if (mmx < 0 || mmx == ROW || mmy < 0 || mmy == COL) return;
                QVector<BLOCK*> target2 = targetGrid(mmx, mmy);
                if (target2.size()) return;
                PLAYER->move(mx, my);
                target[0]->move(mmx, mmy);
                target[1]->move(mmx, mmy);
            }
        }
    }
    else {
        if (cur.size() == 1) {//当前格内1个方块b
            if (cur[0]->getDirection() == d) {//从当前方块开口出来
                PLAYER->move(mx, my);
            }
            else {
                if (target.size()) return;
                PLAYER->move(mx, my);
                cur[0]->move(mx, my);
            }
        }
        else {//当前格内2个方块
            PLAYER->move(mx, my);
        }
    }
    if (Victory()) {
        qDebug()<<"Yes";
    }
}

bool MAP::Victory()
{
    for(int i=0, cnt=0; i<blockPos.size(); ++i){
        cnt++;
        if(cnt == 3){
            cnt = 0;
            int x = blockPos[i]->getPos().x(), y = blockPos[i]->getPos().y();
            BLOCK_COLOR color = blockPos[i]->getColor();
            QVector<BLOCK*> tmp = targetGrid(x, y);
            if(tmp.size() != 2) return false;
            for(int j=0; i<2; ++j){
                if(tmp[j]->getColor() != color) return false;
            }
        }
    }
    return true;
}

QVector<BLOCK*> MAP::targetGrid(int x, int y) {
    QVector<BLOCK*> ret;
    for (BLOCK* bp : blockPos) {
        if (bp->getState() != GRID_STATE::FINISH && bp->getPos().x() == x && bp->getPos().y() == y) {
            ret.push_back(bp);
        }
    }
    return ret;
}

bool MAP::canInto(BLOCK *bl, int d) {
    return bl->getDirection() == um[d];
}
