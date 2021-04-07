#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    ui->graphicsView->setStyleSheet("QGraphicsView {background-color: white}");

    scene->setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
}

MainWindow::~MainWindow()
{
    request_t request;
    request.action = QUIT;
    collection_actions(request);

    delete ui;
}

err_t MainWindow::draw(void)
{
    canvas_t canvas;
    canvas.scene = ui->graphicsView->scene();
    canvas.width = canvas.scene->width();
    canvas.height = canvas.scene->height();

    request_t request;
    request.action = DRAW;
    request.canvas = canvas;

    return collection_actions(request);
}

void MainWindow::on_pushButton_download_fig_clicked()
{
    request_t request;
    request.action = DOWNLOAD_FIGURE;
    request.file_name = "/Users/kirill/Documents/bmstu/oop/lab_1/data.txt";

    err_t rc = collection_actions(request);
    if (rc)
    {
        error_message(rc);
        return;
    }

    rc = draw();
    if (rc)
        error_message(rc);
}

void MainWindow::on_pushButton_turn_clicked()
{
    request_t request;
    request.action = TURN;

    request.turn.angle_x = ui->doubleSpinBox_angle_x->value();
    request.turn.angle_y = ui->doubleSpinBox_angle_y->value();
    request.turn.angle_z = ui->doubleSpinBox_angle_z->value();

    err_t rc = collection_actions(request);
    if (rc)
    {
        error_message(rc);
        return;
    }

    rc = draw();
    if (rc)
        error_message(rc);
}

void MainWindow::on_pushButton_move_clicked()
{
    request_t request;
    request.action = MOVE;

    request.move.dx = ui->doubleSpinBox_dx->value();
    request.move.dy = ui->doubleSpinBox_dy->value();
    request.move.dz = ui->doubleSpinBox_dz->value();

    err_t rc = collection_actions(request);
    if (rc)
    {
        error_message(rc);
        return;
    }

    rc = draw();
    if (rc)
        error_message(rc);
}

void MainWindow::on_pushButton_scale_clicked()
{
    request_t request;
    request.action = SCALE;

    request.scale.kx = ui->doubleSpinBox_kx->value();
    request.scale.ky = ui->doubleSpinBox_ky->value();
    request.scale.kz = ui->doubleSpinBox_kz->value();

    err_t rc = collection_actions(request);
    if (rc)
    {
        error_message(rc);
        return;
    }

    rc = draw();
    if (rc)
        error_message(rc);
}
