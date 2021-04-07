#ifndef ACTIONS_H
#define ACTIONS_H

#include "figure.h"
#include "draw.h"
#include "data.h"
#include "err.h"


enum action
{
    DOWNLOAD_FIGURE,
    TURN,
    MOVE,
    SCALE,
    DRAW,
    QUIT
};

struct request
{
    enum action action;
    union
    {
        const char *file_name;
        canvas_t canvas;
        turn_t turn;
        move_t move;
        scale_t scale;
    };
};

using request_t = struct request;

err_t collection_actions(request_t &action);

#endif
