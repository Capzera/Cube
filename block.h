#ifndef BLOCK_H
#define BLOCK_H

#include <QPoint>
#include <QVector>

enum BLOCK_SIZE{
    SMALL,
    BIG,
    NONE
};

enum BLOCK_DIRECTION{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
};

enum BLOCK_COLOR {//方格A颜色
    BLACK = 0,
    RED,
    YELLOW,
    BLUE,
    GREEN,
    WHITE
};

enum GRID_STATE {//方格状态
    SPACE = 0, //空白
    PLAYER,//玩家
    BLOCKS,//方块
    FINISH//终点
};

class BLOCK
{
public:
    BLOCK();
    BLOCK(int, int, int, int, int, int);
    BLOCK_COLOR getColor();
    GRID_STATE getState();
    BLOCK_DIRECTION getDirection();
    BLOCK_SIZE getSize();
    QPoint getPos();
    void move(int&, int&);//移动
    bool isSmall();
    bool isBig();
    ~BLOCK();
private:
    enum GRID_STATE _state;
    enum BLOCK_COLOR _color;
    enum BLOCK_DIRECTION _direction;
    enum BLOCK_SIZE _size;
    QPoint _pos;

};
#endif // BLOCK_H
