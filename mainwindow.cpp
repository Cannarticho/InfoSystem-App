#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    cpuWidget_(this), // Pass the mainWindow as parent for cpuWidget
    memoryWidget_(this)
{
    ui->setupUi(this);
    // Create new layout for the mainWindow and add the cpuWidget
    ui->centralwidget->setLayout(new QHBoxLayout());
    ui->centralwidget->layout()->addWidget(&cpuWidget_);
    ui->centralwidget->layout()->addWidget(&memoryWidget_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

