#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    InitAllControl();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::InitAllControl()
{
    connect(ui->pbtnEn2Cn, &QPushButton::clicked, this, &MainWindow::OnEn2CnClicked);
    connect(ui->pbtnCn2Cn, &QPushButton::clicked, this, &MainWindow::OnCn2CnClicked);

    //默认选中英文转中文
    OnEn2CnClicked();
}

void MainWindow::OnEn2CnClicked()
{
    ui->pbtnEn2Cn->setChecked(true);
    ui->pbtnCn2Cn->setChecked(false);

    ui->stackedWidget->setCurrentWidget(ui->pageEn2Cn);
}

void MainWindow::OnCn2CnClicked()
{
    ui->pbtnEn2Cn->setChecked(false);
    ui->pbtnCn2Cn->setChecked(true);

    ui->stackedWidget->setCurrentWidget(ui->pageCn2Cn);
}
