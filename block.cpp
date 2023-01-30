#include "block.h"

 BLOCK::BLOCK(GRID_STATE state, BLOCK_COLOR color, BLOCK_STATE block_state, int x, int y) :
     _state(state), _color(color), _block_state(block_state), _x(x), _y(y)
 {}

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

 int BLOCK::getRow()
 {return this->_x;}

 int BLOCK::getCol()
 {return this->_y;}
