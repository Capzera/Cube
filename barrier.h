#ifndef BARRIER_H
#define BARRIER_H

#include <QPoint>

enum BARRIER_STATE{
    SOLID
};

enum BARRIER_COLOR{
    BLACK
};

class BARRIER
{
public:
    BARRIER();
    BARRIER(int x, int y, int color, int state);
    ~BARRIER();
public:
    bool isBarrier();
    QPoint getPos();

public:
    QPoint _pos;
    enum BARRIER_COLOR _color;
    enum BARRIER_STATE _state;
};

#endif // BARRIER_H
