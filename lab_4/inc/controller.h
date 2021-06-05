#pragma once

#include <QObject>
#include <QVector>

#include "constants.h"

class Controller : public QObject
{
Q_OBJECT

    enum ControllerState
    {
        FREE,
        BUSY
    };

public:
    explicit Controller(QObject *parent = nullptr);

    void set_target(int floor);

signals:
    void signal_target_is_set(int floor, Direction dir);
    void signal_targets_found(int floor);

public slots:
    void target_setting(int new_floor);
    void target_updating();

private:
    int curr_floor;
    int target_floor;

    QVector<bool> visit_floors;
    ControllerState state;
    Direction direction;

    int find_next_floor();
    int find_target();
    bool update_target(int floor);
    void update_direction();
};
