#include "actions.h"

err_t collection_actions(request_t &request)
{
    static figure_t figure = figure_init();
    err_t rc = OK;

    switch (request.action)
    {
        case DOWNLOAD_FIGURE:
            rc = download_figure(figure, request.file_name);
            break;
        case MOVE:
            rc = move_figure(figure, request.move);
            break;
        case SCALE:
            rc = scale_figure(figure, request.scale);
            break;
        case TURN:
            rc = turn_figure(figure, request.turn);
            break;
        case DRAW:
            rc = draw_figure(figure, request.canvas);
            break;
        case QUIT:
            free_figure(figure);
            break;
        default:
            rc = UNKNOWN_COMMAND;
    }

    return rc;
}
