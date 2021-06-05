#pragma once

#include <QObject>
#include <QTextEdit>

#include "cabin.h"
#include "controller.h"

class Lift : public QObject
{
Q_OBJECT

public:
    Lift();

    void click_btn(int btn_number);

private:
    Controller controller;
    Cabin cabin;
};
