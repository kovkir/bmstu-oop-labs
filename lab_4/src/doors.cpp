#include "../inc/doors.h"
#include "../inc/color.h"

#include <QDebug>

Doors::Doors(QObject *parent) : QObject(parent), state(CLOSED)
{
    passenger_waiting_timer.setInterval(PASSENGER_WAITING_DELAY);
    passenger_waiting_timer.setSingleShot(true);
    open_timer.setSingleShot(true);
    close_timer.setSingleShot(true);

    QObject::connect(&this->open_timer, SIGNAL(timeout()), this, SLOT(doors_open()));
    QObject::connect(this, SIGNAL(opened()), &this->passenger_waiting_timer, SLOT(start()));
    QObject::connect(&this->passenger_waiting_timer, SIGNAL(timeout()), this, SLOT(doors_closing()));
    QObject::connect(&this->close_timer, SIGNAL(timeout()), this, SLOT(doors_close()));
}

void Doors::doors_opening()
{
    if (state != CLOSING && state != CLOSED)
        return;

    if (state == CLOSED)
    {
        open_timer.start(DOORS_DEFAULT_DELAY);
    }
    else
    {
        int remaining_time = close_timer.remainingTime();
        close_timer.stop();
        open_timer.start(DOORS_DEFAULT_DELAY - remaining_time);
    }

    state = OPENING;

    qDebug() << SET_COLOR GREEN << "двери открываются..." 
             << SET_COLOR BASE_COLOR;
}

void Doors::doors_closing()
{
    if (state != OPENED)
        return;

    state = CLOSING;

    close_timer.start(DOORS_DEFAULT_DELAY);

    qDebug() << SET_COLOR RED << "двери закрываются..." 
             << SET_COLOR BASE_COLOR;
}

void Doors::doors_open()
{
    if (state != OPENING)
        return;

    state = OPENED;

    qDebug() << SET_COLOR GREEN << "двери открыты" 
             << SET_COLOR BASE_COLOR;

    emit opened();
}

void Doors::doors_close()
{
    if (state != CLOSING)
        return;

    state = CLOSED;

    qDebug() << SET_COLOR RED << "двери закрыты" 
             << SET_COLOR BASE_COLOR;

    emit closed();
}
