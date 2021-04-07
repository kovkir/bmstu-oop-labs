#include "wrap_funcs.h"

double get_cos(const double &angle)
{
    return cos(TO_RADIANS(angle));
}

double get_sin(const double &angle)
{
    return sin(TO_RADIANS(angle));
}

err_t clear_scene(const canvas_t &canvas)
{
    if (!canvas.scene)
        return SCENE_WRONG;

    canvas.scene->clear();
    return OK;
}

err_t draw_line(const point_t &p1, const point_t &p2, const canvas_t &canvas)
{
    if (!canvas.scene)
        return SCENE_WRONG;

    canvas.scene->addLine(p1.x, p1.y, p2.x, p2.y, QPen(Qt::red, 3));

    return OK;
}
