#include "widget.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Widget w;
    int currentScreen = a.desktop()->screenNumber(&w);//程序所在的屏幕编号
    QRect rect = a.desktop()->screenGeometry(currentScreen);//程序所在屏幕尺寸
    w.move((rect.width() - w.width()) / 2, (rect.height() - w.height()) / 2);//移动到所在屏幕中间
    w.show();
    return a.exec();
}
