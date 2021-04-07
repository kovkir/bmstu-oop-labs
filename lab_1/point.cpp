#include "point.h"

err_t read_point(point_t &point, FILE *f)
{
    if (f == NULL)
        return FILE_OPEN_ERROR;

    if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
        return READ_FILE_ERROR;

    return OK;
}

static void turn_xp(point_t &point, const double &angle)
{
    double cos_angle = get_cos(angle);
    double sin_angle = get_sin(angle);

    double copy_y = point.y;

    point.y = point.y * cos_angle + point.z * sin_angle;
    point.z = -copy_y * sin_angle + point.z * cos_angle;
}

static void turn_yp(point_t &point, const double &angle)
{
    double cos_angle = get_cos(angle);
    double sin_angle = get_sin(angle);

    double copy_x = point.x;

    point.x = point.x * cos_angle + point.z * sin_angle;
    point.z = -copy_x * sin_angle + point.z * cos_angle;
}

static void turn_zp(point_t &point, const double &angle)
{
    double cos_angle = get_cos(angle);
    double sin_angle = get_sin(angle);

    double copy_x = point.x;

    point.x = point.x * cos_angle + point.y * sin_angle;
    point.y = -copy_x * sin_angle + point.y * cos_angle;
}

void turn_point(point_t &point, const turn_t &turn)
{
    turn_xp(point, turn.angle_x);
    turn_yp(point, turn.angle_y);
    turn_zp(point, turn.angle_z);
}

void move_point(point_t &point, const move_t &move)
{
    point.x += move.dx;
    point.y += move.dy;
    point.z += move.dz;
}

void scale_point(point_t &point, const scale_t &scale)
{
    point.x *= scale.kx;
    point.y *= scale.ky;
    point.z *= scale.kz;
}
