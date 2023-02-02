#include "block.h"

 BLOCK_COLOR BLOCK::getColor()
 {
     return this->_color;
 }

 GRID_STATE  BLOCK::getState()
 {
     return this->_state;
 }

 QPoint BLOCK::getPos()
 {
     return this->_pos;
 }

 BLOCK_DIRECTION BLOCK::getDirection()
 {
     return _direction;
 }

 BLOCK_SIZE BLOCK::getSize()
 {
     return _size;
 }

 //2-方块 3-终点
 //黑0 红1 黄2 蓝3 绿4 白5
 //上1 下2 左3 右4
 //小0 大1 其他2
 BLOCK::BLOCK(int x, int y, int state, int color, int direction, int size)//
{
    _state = (enum GRID_STATE) state;
    _color = (enum BLOCK_COLOR) color;
    _direction = (enum BLOCK_DIRECTION) direction;
    _size = (enum BLOCK_SIZE) size;
    _pos = QPoint(x, y);
}

 void BLOCK::changColor(int color)
 {
     _color = (enum BLOCK_COLOR) color;
 }

void BLOCK::move(int& x, int& y) {
    _pos.setX(x);
    _pos.setY(y);
}

bool BLOCK::isSmall() {
    return _size == BLOCK_SIZE::SMALL;
}

bool BLOCK::isBig() {
    return _size == BLOCK_SIZE::BIG;
}

BLOCK::BLOCK(){}

BLOCK::~BLOCK(){}
