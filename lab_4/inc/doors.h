#pragma once

#include <QObject>

#include "constants.h"

class Doors : public QObject
{
Q_OBJECT

    enum DoorsState
    {
        OPENING,
        OPENED,
        CLOSING,
        CLOSED
    };

public:
    explicit Doors(QObject *parent = nullptr);

signals:
    void closed();
    void opened();

public slots:
    void doors_opening();
    void doors_closing();
    void doors_open();
    void doors_close();

private:
    DoorsState state;
    QTimer open_timer;
    QTimer close_timer;
    QTimer passenger_waiting_timer;
};
