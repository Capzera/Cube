#ifndef BARRIER_H
#define BARRIER_H

#include <QPoint>


class BARRIER
{
public:
    BARRIER();
    BARRIER(int, int);
    ~BARRIER();
public:
    bool isBarrier(int, int);
    QPoint getPos();

public:
    QPoint _pos;
};

#endif // BARRIER_H
