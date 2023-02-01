#ifndef BARRIER_H
#define BARRIER_H

#include <QPoint>

enum BARRIER_COLOR
{
    BAR_BLACK
};

enum BARRIER_STATE{
    SOLID
};

class BARRIER
{
public:
    BARRIER();
    BARRIER(int, int, int, int);
    ~BARRIER();
public:
    bool isBarrier(int, int);
    QPoint getPos();
    BARRIER_COLOR getColor();
    BARRIER_STATE getState();
public:
    QPoint _pos;
    enum BARRIER_COLOR _color;
    enum BARRIER_STATE _state;
};

#endif // BARRIER_H
