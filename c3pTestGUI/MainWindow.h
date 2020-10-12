#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include <atomic>

#include "./util/dynamicUI.h"
#include "./util/PluginManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
    void on_pushButton_reconstruct_clicked();
    
private:
    Ui::MainWindow *ui;
    PluginManager pluginManager;
    std::atomic<bool> isReconRunning;
};
#endif // MAINWINDOW_H
