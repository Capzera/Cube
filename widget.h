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

class Widget : public QWidget {
    Q_OBJECT
public slots:
    void nextLevel();//下一关按钮槽
    void lastLevel();//上一关按钮槽
    void Reset();//重开
    //void Start();//暂定没用
public:
    Widget(QWidget *parent = 0);
    //void paintEvent(QPaintEvent *);//画布事件
    void keyPressEvent(QKeyEvent *);//键盘监听事件
    void Init();//初始化函数
    int LEVEL = 1, MAX_LEVEL = 2;//关卡数定义
    QPushButton *btn1, *btn2, *btn3;//按钮类
    QLineEdit *le1;//单行文本框
    MAP *M;
    ~Widget();
};

#endif // WIDGET_H
