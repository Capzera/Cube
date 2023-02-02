#ifndef BARRIER_H
#define BARRIER_H

#include <QPoint>

enum BARRIER_COLOR
{
    BAR_BLACK,
    BAR_RED,
    BAR_YELLOW,
    BAR_BLUE,
    BAR_GREEN
};

enum BARRIER_STATE{
    SOLID,
    DIAGCROSSPATTERN
};

class BARRIER
{
public:
    BARRIER();
    BARRIER(int, int, int, int);
    ~BARRIER();
public:
    bool isBarrier(int, int);
    bool isCrossPattern(int , int);
    QPoint getPos();
    BARRIER_COLOR getColor();
    BARRIER_STATE getState();
private:
    QPoint _pos;
    enum BARRIER_COLOR _color;
    enum BARRIER_STATE _state;
};

#endif // BARRIER_H
