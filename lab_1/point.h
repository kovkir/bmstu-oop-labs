#ifndef POINT_H
#define POINT_H

#include <cstdio>

#include "wrap_funcs.h"
#include "data.h"
#include "err.h"

err_t read_point(point_t &point, FILE *f);

void turn_point(point_t &point, const turn_t &turn);

void move_point(point_t &point, const move_t &move);

void scale_point(point_t &point, const scale_t &scale);

#endif
