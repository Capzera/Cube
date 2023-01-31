#include "barrier.h"

BARRIER::BARRIER() {}

BARRIER::BARRIER(int x, int y) : _pos(QPoint(x, y)){}

bool BARRIER::isBarrier(int x, int y) {
    return (_pos.x() == x && _pos.y() == y);
}

QPoint BARRIER::getPos() {
    return _pos;
}

BARRIER::~BARRIER() {}
