#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_reconstruct_clicked()
{
    PluginManager pm;
//    if(pm.loadPlugin("./osem/libc3pOSEM")) {
//        pm.getPluginInstance()->start("./osem/config.ini");
//    }
    if(pm.loadPlugin("./osemCPU/libOsemCPU")) {
        pm.getPluginInstance()->start("./osemCPU/config.ini");
    }
}
