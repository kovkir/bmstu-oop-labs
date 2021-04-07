#ifndef ERR_H
#define ERR_H

#include <QMessageBox>

enum error_code
{
    OK,
    FILE_OPEN_ERROR,
    FILE_CLOSE_ERROR,
    READ_FILE_ERROR,
    MEMORY_ALLOCATION_ERROR,
    AMOUNT_OF_POINTS_WRONG,
    AMOUNT_OF_CONNECTIONS_WRONG,
    SCENE_WRONG,
    COEF_SCALE_WRQNG,
    FIGURE_NOT_LOADED,
    UNKNOWN_COMMAND
};

using err_t = enum error_code;

void error_message(err_t &error);

#endif
