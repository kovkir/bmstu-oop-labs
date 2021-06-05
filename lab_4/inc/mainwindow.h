#pragma once

#include <QMainWindow>
#include "lift.h"

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void button_clicked(int btn_number);

private:
    Ui::MainWindow *ui;
    Lift lift;
};
