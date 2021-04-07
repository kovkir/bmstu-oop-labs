#ifndef POINTS_H
#define POINTS_H

#include <cstdio>
#include <cstdlib>

#include "point.h"
#include "data.h"
#include "err.h"

void free_points(points_t &points);

err_t read_amount(int &amount, FILE *f);

err_t read_all_about_points(points_t &points, FILE *f);

err_t move_all_points(points_t &points, const move_t &move);

err_t scale_all_points(points_t &points, const scale_t &scale);

err_t turn_all_points(points_t &points, const turn_t &turn);

#endif
