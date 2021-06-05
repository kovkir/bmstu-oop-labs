#include <QString>
#include <QDebug>

#include "../inc/cabin.h"
#include "../inc/color.h"


Cabin::Cabin(QObject *parent) : QObject(parent), curr_floor(START_FLOOR), 
                                target_floor(NO_TARGET), state(UNLOCKED), direction(STAY)
{
    pass_floor_timer.setSingleShot(true);

    QObject::connect(this, SIGNAL(need_floor(int)), this, SLOT(cabin_stopped()));
    QObject::connect(this, SIGNAL(stopped(int)), this, SLOT(cabin_lock()));
    QObject::connect(this, SIGNAL(locked()), &this->doors, SLOT(doors_opening()));
    QObject::connect(this, SIGNAL(prepared()),   this, SLOT(cabin_move()));
    QObject::connect(&this->doors, SIGNAL(closed()), this, SLOT(cabin_unlock()));
    QObject::connect(&this->pass_floor_timer, SIGNAL(timeout()), this, SLOT(cabin_move()));
}

void Cabin::cabin_move()
{
    if (state != PREPARE && state != MOVE)
        return;

    if (state == MOVE)
    {
        curr_floor += direction;

        qDebug() << SET_COLOR PURPURE << " ... " << SET_COLOR BASE_COLOR << 
                    "(текущий этаж - " << curr_floor << ")";

        emit floor_passed(curr_floor);
    }

    state = MOVE;

    if (curr_floor == target_floor)
        emit need_floor(curr_floor);
    else
        pass_floor_timer.start(ONE_FLOOR_PASS_TIME);
}

void Cabin::cabin_prepare(int floor, Direction dir)
{
    if (state != UNLOCKED)
        return;

    state = PREPARE;

    target_floor = floor;
    direction = dir;

    emit prepared();
}

void Cabin::cabin_stopped()
{
    if (state != MOVE)
        return;

    state = STOPPED;

    qDebug() << SET_COLOR BLUE << "\nЛифт прибыл на этаж № " << curr_floor << "\n" <<
                SET_COLOR BASE_COLOR;

    emit stopped(curr_floor);
}

void Cabin::cabin_lock()
{
    if (state != STOPPED)
        return;

    state = LOCKED;

    qDebug() << "🔐";

    emit locked();
}

void Cabin::cabin_unlock()
{
    if (state != LOCKED)
        return;

    state = UNLOCKED;

    qDebug() << "🔓\n";

    emit unlocked();
}
