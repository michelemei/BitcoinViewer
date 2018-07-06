#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bitcoinwatcher.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    worker = std::unique_ptr<BitcoinWatcher>(new BitcoinWatcher());

    connect(worker.get(), SIGNAL(bitcoin2EurStr(QString)),
            ui->bitcoinValue, SLOT(setText(QString)));

    connect(worker.get(), SIGNAL(datetimeStr(QString)),
            ui->datetimeLabel, SLOT(setText(QString)));

    manageWorker();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::manageWorker()
{
    // worker is always a valid pointer (see ctor)
    if (worker->isActive())
    {
        ui->ctrlButton->setText("Start");
        worker->stop();
    }
    else
    {
        ui->ctrlButton->setText("Stop");
        worker->start();
    }
}

void MainWindow::on_ctrlButton_clicked()
{
    manageWorker();
}
