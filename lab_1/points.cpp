#include "points.h"

static err_t allocate_points(points_t &points)
{
    if (points.amount <= 0)
        return AMOUNT_OF_POINTS_WRONG;

    point_t *temp_arr = (point_t*) malloc(points.amount * sizeof(point_t));
    if (!temp_arr)
        return MEMORY_ALLOCATION_ERROR;

    points.arr_points = temp_arr;

    return OK;
}

void free_points(points_t &points)
{
    free(points.arr_points);

    points.arr_points = NULL;
    points.amount = 0;
}

err_t read_amount(int &amount, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    if (fscanf(f, "%d", &amount) != 1)
        return READ_FILE_ERROR;

    if (amount <= 0)
        return AMOUNT_OF_POINTS_WRONG;

    return OK;
}

static err_t read_points(points_t &points, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;
    else if (points.amount <= 0)
        return AMOUNT_OF_POINTS_WRONG;
    else if (!points.arr_points)
        return MEMORY_ALLOCATION_ERROR;

    err_t rc = OK;

    for (int i = 0; rc == OK && i < points.amount; i++)
        rc = read_point(points.arr_points[i], f);

    return rc;
}

err_t read_all_about_points(points_t &points, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    err_t rc = read_amount(points.amount, f);
    if (rc)
        return rc;

    rc = allocate_points(points);
    if (rc)
        return rc;

    rc = read_points(points, f);
    if (rc)
        free_points(points);

    return rc;
}

err_t move_all_points(points_t &points, const move_t &move)
{
    if (!points.arr_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.amount; i++)
        move_point(points.arr_points[i], move);

    return OK;
}

err_t scale_all_points(points_t &points, const scale_t &scale)
{
    if (!points.arr_points)
        return FIGURE_NOT_LOADED;
    else if(scale.kx == 0 ||
            scale.ky == 0 ||
            scale.kz == 0)
        return COEF_SCALE_WRQNG;

    for (int i = 0; i < points.amount; i++)
        scale_point(points.arr_points[i], scale);

    return OK;
}

err_t turn_all_points(points_t &points, const turn_t &turn)
{
    if (!points.arr_points)
        return FIGURE_NOT_LOADED;

    for (int i = 0; i < points.amount; i++)
        turn_point(points.arr_points[i], turn);

    return OK;
}
