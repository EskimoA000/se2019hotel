#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  client(this)
{
  ui->setupUi(this);
  connect(&client, SIGNAL(sgn_refresh(Room)), this, SLOT(refresh(Room)));
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::refresh(Room room)
{
  ui->DispTemp->setNum(room.temp);
  ui->DispSettemp->setNum(room.settemp);
  ui->DispWdspd->setNum(room.wdspd);
  ui->DispSetwdspd->setNum(room.setwdspd);
}
