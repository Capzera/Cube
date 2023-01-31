#ifndef BLOCK_H
#define BLOCK_H

#include <QPoint>
#include <QVector>

enum BLOCK_SIZE{
    BIG,
    SMALL
};

enum BLOCK_STATE {//方块状态
    SMALL_LEFT,//小型方块开口朝左
    SMALL_RIGHT,
    SMALL_UP,
    SMALL_DOWN,
    BIG_LEFT,//大型方块开口朝右
    BIG_RIGHT,
    BIG_UP,
    BIG_DOWN
};

enum BLOCK_DIRECTION{
    UP = 1,
    DOWN,
    LEFT,
    RIGHT
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
    BARRIER,//障碍物
    BLOCKS,//方块
    FINISH//终点
};

class BLOCK
{
public:
    BLOCK();
    BLOCK(GRID_STATE state, BLOCK_COLOR color, BLOCK_STATE block_state, BLOCK_DIRECTION director, BLOCK_SIZE size, int x, int y);
    BLOCK(int state, int color, int block_state, int direction, int size, int x, int y);
    ~BLOCK();
public:
    BLOCK_COLOR getColor();
    GRID_STATE getState();
    BLOCK_STATE getBlockState();
    BLOCK_DIRECTION getDirection();
    BLOCK_SIZE getSize();
    QPoint getPos();
    void move(int&, int&);//移动
private:
    enum GRID_STATE _state;
    enum BLOCK_COLOR _color;
    enum BLOCK_STATE _block_state;
    enum BLOCK_DIRECTION _direction;
    enum BLOCK_SIZE _size;
    QPoint _pos;

};
#endif // BLOCK_H
