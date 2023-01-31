#ifndef BARRIER_H
#define BARRIER_H

#include <QPoint>

class BARRIER
{
public:
    BARRIER();
    BARRIER(int x, int y);
    ~BARRIER();
public:
    bool isBarrier();
    QPoint getPos();
public:
    QPoint _pos;
};

#endif // BARRIER_H
