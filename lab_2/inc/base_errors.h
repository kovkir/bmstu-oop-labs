#ifndef BASE_ERRORS_H
#define BASE_ERRORS_H

#include <exception>
#include <string>

class base_error : public std::exception
{
public:
    base_error(
        std::string filename, 
        std::string classname, 
        int line, 
        const char *time,
        std::string info = "Ошибка!")
    {
        err_info = "\nFile name: " + filename + 
                   "\nClass: " + classname +
                   "\nLine: " + std::to_string(line) +
                   "\nTime: " + time + 
                     "Info: " + info;
    }

    virtual const char* what() const noexcept override
    {
        return err_info.c_str();
    }

protected:
    std::string err_info;
};

#endif
