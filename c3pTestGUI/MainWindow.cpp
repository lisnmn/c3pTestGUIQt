#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <thread>

#include <QLibrary>
#include <QDebug>
#include <QMessageBox>

#include "include/libosem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    LibOSEM libOSEM;
//    QLibrary qLib("./liblibOSEM");
//    if(qLib.load()) {
//        qDebug() << "Library OSEMOld loaded";
//        LibOSEM libOSEM;
//    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_reconstruct_clicked()
{
//    if(pm.loadPlugin("./osem/libc3pOSEM")) {
//        pm.getPluginInstance()->start("./osem/config.ini");
//    }
    if(isReconRunning) {
        QMessageBox::warning(this, "Warning", "Please wait for Reconstruct finishing.");
        return;
    }
    
    this->isReconRunning = true;
    
    if(!pluginManager.loadPlugin("./osemCPU/libOsemCPU")) {
        return;
    }
    std::thread start([this] {
        pluginManager.getPluginInstance()->start("./osemCPU/config.ini");
    });
    std::thread progress([this] {
        auto pluginInstance = this->pluginManager.getPluginInstance();
        while(pluginInstance->progress() <= 1.0) {
            if(isReconRunning == false) {
                return;
            }
            ui->progressBar->setValue(int(pluginInstance->progress() * 100));
        }
        QMessageBox::information(nullptr, "OK", "Reconstruct finished.");
        this->isReconRunning = false;
    });
    start.detach();
    progress.detach();
}
