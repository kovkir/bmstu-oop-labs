#include "draw.h"

static point_t conversion(point_t point, const canvas_t &canvas)
{
    point.x += canvas.width / 2;
    point.y += canvas.height / 2;

    return point;
}

static p_line_t get_points(const connection_t &connect, const point_t *arr_points,
                           const canvas_t &canvas)
{
    p_line_t p_line;

    p_line.one_point = conversion(arr_points[connect.one_point], canvas);
    p_line.two_point = conversion(arr_points[connect.two_point], canvas);

    return p_line;
}

static err_t draw_lines(const points_t &points, const connections_t &connections,
                        const canvas_t &canvas)
{
    if (points.arr_points == NULL || connections.arr_connect == NULL)
        return MEMORY_ALLOCATION_ERROR;
    else if (!canvas.scene)
        return SCENE_WRONG;

    p_line_t p_line;
    err_t rc = OK;

    for (int i = 0; i < connections.amount && rc == OK; i++)
    {
        p_line = get_points(connections.arr_connect[i], points.arr_points, canvas);
        rc = draw_line(p_line.one_point, p_line.two_point, canvas);
    }

    return rc;
}

err_t draw_figure(const figure_t &figure, canvas_t &canvas)
{
    err_t rc = clear_scene(canvas);
    if (rc)
        return rc;

    rc = draw_lines(figure.points, figure.connections, canvas);

    return rc;
}
