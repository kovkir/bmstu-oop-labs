#pragma once

#include <QTextEdit>
#include <QTimer>

enum Direction
{
    DOWN = -1,
    STAY = 0,
    UP = 1
};

#define NUM_OF_FLOORS 10
#define START_FLOOR   1

#define ONE_FLOOR_PASS_TIME     1000
#define DOORS_DEFAULT_DELAY     1000
#define PASSENGER_WAITING_DELAY 1000

#define NO_TARGET (-1)

