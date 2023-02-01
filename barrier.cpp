#include "barrier.h"

BARRIER::BARRIER() {}

BARRIER::BARRIER(int x, int y, int color, int state) : _pos(QPoint(x, y))
{
    _color = (BARRIER_COLOR) color;
    _state = (BARRIER_STATE) state;
}

bool BARRIER::isBarrier(int x, int y) {
    return (_pos.x() == x && _pos.y() == y);
}

BARRIER_COLOR BARRIER::getColor()
{
    return _color;
}

BARRIER_STATE BARRIER::getState()
{
    return _state;
}

QPoint BARRIER::getPos() {
    return _pos;
}

BARRIER::~BARRIER() {}
