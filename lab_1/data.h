#ifndef DATA_H
#define DATA_H

struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

struct points
{
    int amount;
    point_t *arr_points;
};

using points_t = struct points;

struct connection
{
    int one_point;
    int two_point;
};

using connection_t = struct connection;

struct connections
{
    int amount;
    connection_t *arr_connect;
};

using connections_t = struct connections;

struct figure
{
    points_t points;
    connections_t connections;
};

using figure_t = struct figure;

struct turn
{
    double angle_x;
    double angle_y;
    double angle_z;
};

struct move
{
    double dx;
    double dy;
    double dz;
};

struct scale
{
    double kx;
    double ky;
    double kz;
};

using turn_t = struct turn;
using move_t = struct move;
using scale_t = struct scale;

#endif
