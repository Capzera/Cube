#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include <QPainter>
#include <QKeyEvent>
#include <QColor>
#include <QPen>
#include <QPushButton>
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QVector>
#include <QString>
#include "map.h"

enum BLOCK_STATE {//方块状态
    SMALL_LEFT,//小型方块开口朝左
    SMALL_RIGHT,
    SMALL_UP,
    SMALL_DOWN,
    BIG_LEFT,//大型方块开口朝右
    BIG_RIGHT,
    BIG_UP,
    BIG_DOWN
};

enum BLOCK_COLOR {//方块颜色
    RED,
    YELLOW,
    BLUE,
    GREEN
};

enum GRID_STATE {//方格状态
    PLAYER,//玩家
    BARRIER,//障碍物
    BLOCK,//方块
    FINISH//终点
};

class Widget : public QWidget {
    Q_OBJECT
public slots:
    void nextLevel();//下一关按钮槽
    void lastLevel();//上一关按钮槽
    //void Reset();//重开
    //void Start();//暂定没用
public:
    Widget(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *);//画布事件
    void keyPressEvent(QKeyEvent *);//键盘监听事件
    void operat(int);//玩家移动
    void Init();//初始化函数
    int LEVEL = 1, MAX_LEVEL = 99;//关卡数定义
    QPushButton *btn1, *btn2, *btn3;//按钮类
    QLineEdit *le1;//单行文本框
    MAP *M;
    ~Widget();
};

#endif // WIDGET_H
