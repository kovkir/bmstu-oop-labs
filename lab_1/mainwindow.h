#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "actions.h"
#include "err.h"

#define WIN_WIDTH 700
#define WIN_HEIGHT 590

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    err_t draw(void);

    void on_pushButton_download_fig_clicked();

    void on_pushButton_turn_clicked();

    void on_pushButton_move_clicked();

    void on_pushButton_scale_clicked();
};

#endif
