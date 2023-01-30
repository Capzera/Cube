#include "block.h"

 BLOCK::BLOCK(GRID_STATE state, BLOCK_COLOR color, BLOCK_STATE block_state, int x, int y) :
     _state(state), _color(color), _block_state(block_state), _pos(QPoint(x, y)) {

 }

 BLOCK_COLOR BLOCK::getColor()
 {
     return this->_color;
 }

 GRID_STATE  BLOCK::getState()
 {
     return this->_state;
 }

 BLOCK_STATE BLOCK::getBlockState()
 {
     return this->_block_state;
 }

 QPoint BLOCK::getPos()
 {
     return this->_pos;
 }

BLOCK::BLOCK(int state, int color, int block_state, int x, int y)
{
    _state = (enum GRID_STATE) state;
    _color = (enum BLOCK_COLOR) color;
    _block_state = (enum BLOCK_STATE) block_state;
    _pos = QPoint(x, y);
}

void BLOCK::move(int& x, int& y) {
    _pos.setX(x);
    _pos.setY(y);
}
BLOCK::BLOCK(){}
BLOCK::~BLOCK(){}
