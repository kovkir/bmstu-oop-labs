#include <QDebug>
#include "../inc/color.h"

#include "../inc/ui_mainwindow.h"
#include "../inc/mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < ui->floor_buttons.size(); ++i)
    {
        connect(ui->floor_buttons[i], &QPushButton::pressed, this, [i, this]() 
            { button_clicked(i + 1); });
    }
}

void MainWindow::button_clicked(const int btn_number)
{
    qDebug() << SET_COLOR YELLOW << "\nЛифт вызван на этаж № " << btn_number << "\n" <<
                SET_COLOR BASE_COLOR;

    lift.click_btn(btn_number);
}

MainWindow::~MainWindow()
{
    delete ui;
}
