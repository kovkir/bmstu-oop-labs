#ifndef FIGURE_H
#define FIGURE_H

#include <cstdio>

#include "points.h"
#include "connections.h"
#include "data.h"
#include "err.h"

figure_t &figure_init(void);

void free_figure(figure_t &figure);

err_t download_figure(figure_t &figure, const char *file_name);

err_t move_figure(figure_t &figure, const move_t &move);

err_t scale_figure(figure_t &figure, const scale_t &scale);

err_t turn_figure(figure_t &figure, const turn_t &turn);

#endif
