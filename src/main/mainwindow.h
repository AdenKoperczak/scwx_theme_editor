#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStringList>
#include <QPushButton>
#include <QHBoxLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    void on_file_open(void);
    void on_new_file(void);

    QHBoxLayout mainLayout;
    QPushButton openFile;
    QPushButton newFile;
};

#endif // MAINWINDOW_H
