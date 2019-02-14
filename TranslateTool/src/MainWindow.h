#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
explicit MainWindow(QWidget *parent = nullptr);
~MainWindow();

private slots:
    void OnEn2CnClicked();
    void OnCn2CnClicked();

private:
    void InitAllControl();

private:
Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
