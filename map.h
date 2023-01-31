#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QHash>
#include "block.h"

class MAP : public QWidget
{
    Q_OBJECT
public slots:

public:
    explicit MAP(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void draw_frame();//画边框
    void draw_block();//画方块
    void draw_puzzle_block(BLOCK*);
    void draw_player_block(BLOCK*);
    void draw_finish_block(BLOCK*);
    void getLevel(int);//获取关卡数
    void operat(int);//玩家移动
    void mapInit();//地图预设
    void blockPosInit(int);
public:
    bool checkIsInto(int mx, int my, int d);//是否能进入
    bool checkPush(int mx, int my, int d);//是否能推动
    void blockMove(int mx, int my, int d);//推箱子
   // bool checkBlockState(int x, int y, int mx, int my);
    bool checkOnlyBig(int x, int y);
    bool checkOnlySmall(int x, int y);
    bool checkDirection(int a, int b);
public:
    int ROW = 4, COL = 3, B_wide;//定义游戏区方格长、宽、像素点矩阵宽度
    QVector<QVector<int>> locate_x, locate_y, blocks;//像素坐标记录
    int player_x, player_y;
    BLOCK *PLAYER;
    QVector<QVector<QVector<BLOCK*>>> block_pos;
    QHash<int, int>     um;
};

#endif // MAP_H
