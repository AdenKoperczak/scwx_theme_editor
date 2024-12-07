#include <QApplication>
#include <QLocale>
#include <QSettings>
#include <QStyle>
#include "qt6ct.h"
#include "mainwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QGuiApplication::setDesktopFileName(QStringLiteral("qt6ct"));

    MainWindow w;
    w.show();

    return app.exec();
}
