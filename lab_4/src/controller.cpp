#include "../inc/controller.h"

Controller::Controller(QObject *parent) : QObject(parent), state(FREE), direction(STAY), 
                                          curr_floor(START_FLOOR), target_floor(NO_TARGET), 
                                          visit_floors(NUM_OF_FLOORS, false)
{
    QObject::connect(this, SIGNAL(signal_targets_found(int)), this, SLOT(target_setting(int)));
}

void Controller::set_target(const int floor)
{
    if (visit_floors[floor - 1])
        return;

    state = BUSY;

    visit_floors[floor - 1] = true;

    if (update_target(floor)) 
        update_direction();

    emit signal_target_is_set(find_next_floor(), direction);
}

void Controller::target_updating()
{
    if (state != BUSY)
        return;

    state = FREE;
    visit_floors[curr_floor - 1] = false;

    auto new_target = find_target();

    if (curr_floor == target_floor && new_target == NO_TARGET)
    {
        direction = STAY;
        target_floor = NO_TARGET;
    }
    else
        emit signal_targets_found(new_target);
}

void Controller::target_setting(const int new_floor)
{
    if (state == FREE)
    {
        state = BUSY;

        if (curr_floor == target_floor)
        {
            target_floor = new_floor;
            update_direction();
        }
        
        emit signal_target_is_set(find_next_floor(), direction);
    }
    else
    {
        state = BUSY;
        curr_floor = new_floor;
    }
}

int Controller::find_target()
{
    int target = NO_TARGET;

    if (direction == UP)
    {
        for (int i = 1; i <= curr_floor && target == NO_TARGET; ++i)
            if (visit_floors[i - 1])
                target = i;
    }
    else
    {
        for (int i = NUM_OF_FLOORS; i >= curr_floor && target == NO_TARGET; --i)
            if (visit_floors[i - 1])
                target = i;
    }

    return target;
}

bool Controller::update_target(const int floor)
{
    bool is_updated = false;

    if ((target_floor == NO_TARGET) ||
        (direction == UP   && floor > target_floor) ||
        (direction == DOWN && floor < target_floor))
    {
        is_updated = true;
        target_floor = floor;
    }

    return is_updated;
}

int Controller::find_next_floor()
{
    int next_target = NO_TARGET;

    if (target_floor > curr_floor)
    {
        for (int i = curr_floor; i <= target_floor && next_target == NO_TARGET; i++)
            if (visit_floors[i - 1]) 
                next_target = i;
    }
    else
    {
        for (int i = curr_floor; i >= target_floor && next_target == NO_TARGET; i--)
            if (visit_floors[i - 1]) 
                next_target = i;
    }

    return next_target;
}

void Controller::update_direction()
{   
    if (target_floor < curr_floor)
        direction = DOWN;
    else
        direction = UP;
}
