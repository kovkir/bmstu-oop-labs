#include "err.h"

void error_message(err_t &error)
{
    switch (error)
    {
        case FILE_OPEN_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось открыть файл");
            break;
        case FILE_CLOSE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось закрыть файл");
            break;
        case READ_FILE_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось прочитать файл!");
            break;
        case MEMORY_ALLOCATION_ERROR:
            QMessageBox::critical(NULL, "Ошибка!", "Не удалось выделить память!");
            break;
        case AMOUNT_OF_POINTS_WRONG:
            QMessageBox::critical(NULL, "Ошибка!", "Кол-во точек в файле должно быть > 0!");
            break;
        case AMOUNT_OF_CONNECTIONS_WRONG:
            QMessageBox::critical(NULL, "Ошибка!", "Кол-во связей точек в файле должно быть > 0!");
            break;
        case SCENE_WRONG:
            QMessageBox::critical(NULL, "Ошибка!", "При попытке нарисовать, фигуру произошла ошибка!");
            break;
        case COEF_SCALE_WRQNG:
            QMessageBox::critical(NULL, "Ошибка!", "Коэффициенты масштабирования не должны равняться 0!");
            break;
        case FIGURE_NOT_LOADED:
            QMessageBox::information(NULL, "Информация!", "Фигура не загружена!");
            break;
        default:
            QMessageBox::critical(NULL, "Ошибка!", "Что-то пошло не по плану...");
    }
}
