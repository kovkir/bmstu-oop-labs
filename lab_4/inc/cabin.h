#pragma once

#include <QObject>

#include "constants.h"
#include "controller.h"
#include "doors.h"

class Cabin : public QObject 
{
Q_OBJECT

    enum CabinState
    {
        MOVE,
        STOPPED,
        LOCKED,
        UNLOCKED,
        PREPARE 
    };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void prepared();
    void floor_passed(int floor);
    void need_floor(int floor);
    void stopped(int floor);
    void unlocked();
    void locked();

public slots:
    void cabin_prepare(int floor, Direction dir);
    void cabin_move();
    void cabin_stopped();
    void cabin_lock();
    void cabin_unlock();

private:
    int curr_floor;
    int target_floor;

    CabinState state;
    Direction direction;
    Doors doors;
    QTimer pass_floor_timer;
};
