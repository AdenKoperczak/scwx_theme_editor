#include <QApplication>
#include <QSettings>
#include <QStyle>
#include <QProcessEnvironment>
#include <QMessageBox>
#include <QStyleFactory>
#include <QLibraryInfo>
#include <QFileDialog>
#include "qt6ct.h"
#include "mainwindow.h"
#include "paletteeditdialog.h"

void createColorScheme(const QString &name, const QPalette &palette)
{
    QSettings settings(name, QSettings::IniFormat);
    settings.beginGroup("ColorScheme");

    QStringList activeColors, inactiveColors, disabledColors;
    for (int i = 0; i < QPalette::NColorRoles; i++)
    {
        QPalette::ColorRole role = QPalette::ColorRole(i);
        activeColors << palette.color(QPalette::Active, role).name(QColor::HexArgb);
        inactiveColors << palette.color(QPalette::Inactive, role).name(QColor::HexArgb);
        disabledColors << palette.color(QPalette::Disabled, role).name(QColor::HexArgb);
    }

    settings.setValue("active_colors",activeColors);
    settings.setValue("inactive_colors",inactiveColors);
    settings.setValue("disabled_colors",disabledColors);

    settings.endGroup();
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    mainLayout(this),
    openFile(),
    newFile()
{
    openFile.setText("Open File");
    newFile.setText("New File");

    connect(&openFile,
            &QPushButton::clicked,
            this,
            &MainWindow::on_file_open);

    connect(&newFile,
            &QPushButton::clicked,
            this,
            &MainWindow::on_new_file);

    mainLayout.addWidget(&openFile);
    mainLayout.addWidget(&newFile);
}

MainWindow::~MainWindow()
{
}

void edit_file(QString file)
{
    if (file == QString())
    {
        return;
    }
    QPalette palette = Qt6CT::loadColorScheme(file, QApplication::palette());
    QStyle* style = QApplication::style();

    PaletteEditDialog dialog(palette, style, nullptr);
    if (dialog.exec() == QDialog::Accepted)
    {
        palette = dialog.selectedPalette();
        createColorScheme(file, palette);
    }
}


static const QString filter = QString("Theme File (*.conf);;All (*)");

void MainWindow::on_file_open(void)
{
    QString file = QFileDialog::getOpenFileName(this, "Open File", QString(), filter);
    edit_file(file);
}

void MainWindow::on_new_file(void)
{
    QString file = QFileDialog::getSaveFileName(this, "Create File", QString(), filter);
    edit_file(file);
}

