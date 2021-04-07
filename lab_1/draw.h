#ifndef DRAW_H
#define DRAW_H

#include <QGraphicsView>

#include "wrap_funcs.h"
#include "err.h"
#include "data.h"

struct p_line
{
    point_t one_point;
    point_t two_point;
};

using p_line_t = struct p_line;

err_t draw_figure(const figure_t &figure, canvas_t &canvas);

#endif
