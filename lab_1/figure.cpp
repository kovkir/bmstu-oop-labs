#include "figure.h"

figure_t &figure_init(void)
{
    static figure_t figure;

    figure.points.amount = 0;
    figure.points.arr_points = NULL;

    figure.connections.amount = 0;
    figure.connections.arr_connect = NULL;

    return figure;
}

void free_figure(figure_t &figure)
{
    free_points(figure.points);
    free_connections(figure.connections);
}

static err_t read_figure(figure_t &figure, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    figure = figure_init();

    err_t rc = read_all_about_points(figure.points, f);
    if (rc == OK)
    {
        rc = read_all_about_connections(figure.connections, f);
        if (rc)
            free_points(figure.points);
    }

    return rc;
}

err_t download_figure(figure_t &figure, const char *file_name)
{
    if (file_name == NULL)
        return FILE_OPEN_ERROR;

    FILE *f = fopen(file_name, "r");
    if (f == NULL)
        return FILE_OPEN_ERROR;

    figure_t temp_figure;

    err_t rc = read_figure(temp_figure, f);

    if (fclose(f))
        return FILE_CLOSE_ERROR;

    if (rc == OK)
    {
        free_figure(figure);
        figure = temp_figure;
    }

    return rc;
}

err_t move_figure(figure_t &figure, const move_t &move)
{
    return move_all_points(figure.points, move);
}

err_t scale_figure(figure_t &figure, const scale_t &scale)
{
    return scale_all_points(figure.points, scale);
}

err_t turn_figure(figure_t &figure, const turn_t &turn)
{
    return turn_all_points(figure.points, turn);
}
