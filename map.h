#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QFile>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QMap>
#include "block.h"
#include "barrier.h"

class MAP : public QWidget
{
    Q_OBJECT
public slots:

public:
    explicit MAP(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void draw_frame();//画边框
    void draw_block();//画方块
    void draw_barrier();//画障碍
    void draw_puzzle_block(BLOCK*);
    void draw_player_block(BLOCK*);
    void draw_finish_block(BLOCK*);
    void getLevel(int);//获取关卡数
    void operat(int);//玩家移动
    void mapInit();//地图预设
    void blockPosInit(int);//预设方块
    bool checkIsInto(int, int, int);//是否能进入
    bool checkPush(int, int, int);//是否能推动
    bool canInto (BLOCK*, int);
    bool Victory();//判断胜利
    void blockMove(int, int, int);//推箱子
    QVector<BLOCK*> targetGrid(int, int);//返回目标格指针
public:
    int ROW = 4, COL = 3, B_wide;//定义游戏区方格长、宽、像素点矩阵宽度
    QVector<QVector<int>> locate_x, locate_y, blocks;//像素坐标记录
    int player_x, player_y;
    BLOCK *PLAYER;
    QVector<BLOCK*> blockPos;
    QVector<BARRIER*> barrier;
};

#endif // MAP_H
