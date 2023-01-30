#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QPainter>
#include <QVector>

class MAP : public QWidget
{
    Q_OBJECT
public slots:

public:
    explicit MAP(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    void draw_frame();//画边框
    void draw_block();//画方块
    void mapInit();//地图预设
    int ROW = 15, COL = 20, B_wide = 40;//定义游戏区方格长、宽、像素点矩阵宽度
    QVector<QVector<int>> locate_x, locate_y, blocks;//像素坐标记录
};

#endif // MAP_H
