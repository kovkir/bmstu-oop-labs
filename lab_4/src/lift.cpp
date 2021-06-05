#include "../inc/lift.h"

Lift::Lift()
{
    QObject::connect(&controller, SIGNAL(signal_target_is_set(int, Direction)), 
                     &cabin,      SLOT  (cabin_prepare(int, Direction)));

    QObject::connect(&cabin,      SIGNAL(floor_passed(int)),
                     &controller, SLOT  (target_setting(int)));

    QObject::connect(&cabin,      SIGNAL(unlocked()), 
                     &controller, SLOT  (target_updating()));
}

void Lift::click_btn(const int btn_number)
{
    controller.set_target(btn_number);
}
