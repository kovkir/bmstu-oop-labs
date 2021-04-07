#ifndef WRAP_FUNCS_H
#define WRAP_FUNCS_H

#include <QGraphicsView>
#include <cmath>

#include "err.h"
#include "data.h"

#define PI M_PI
#define TO_RADIANS(angle) ((angle) * PI / 180)

struct canvas
{
    QGraphicsScene *scene;
    double width;
    double height;
};

using canvas_t = struct canvas;

double get_cos(const double &angle);

double get_sin(const double &angle);

err_t clear_scene(const canvas_t &canvas);

err_t draw_line(const point_t &p1, const point_t &p2, const canvas_t &canvas);

#endif
