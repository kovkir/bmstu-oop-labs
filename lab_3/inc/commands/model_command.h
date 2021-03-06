#ifndef MODEL_COMMAND_H
#define MODEL_COMMAND_H

#include <cstddef>
#include <memory>

#include "base_command.h"
#include "../object/object.h"

class MoveModelCommand : public ModelBaseCommand
{
public:
    MoveModelCommand(const double &dx, const double &dy, const double &dz, const std::size_t model_num);

    virtual void exec() override;

private:
    std::size_t _model_num;
    double _dx, _dy, _dz;
};


class ScaleModelCommand : public ModelBaseCommand
{
public:
    ScaleModelCommand(const double &kx, const double &ky, const double &kz, const std::size_t model_num);

    virtual void exec() override;

private:
    std::size_t _model_num;
    double _kx, _ky, _kz;
};


class RotateModelCommand : public ModelBaseCommand
{
public:
    RotateModelCommand(const double &ox, const double &oy, const double &oz, const std::size_t model_num);

    virtual void exec() override;

private:
    std::size_t _model_num;
    double _ox, _oy, _oz;
};


class TransformModelCommand : public ModelBaseCommand
{
public:
    TransformModelCommand(const Dot &move, const Dot &scale, const Dot &spin, const std::size_t model_num);

    virtual void exec() override;

private:
    std::size_t _model_num;
    Dot _move, _scale, _rotate;
};


class AddModelCommand : public ModelBaseCommand
{
public:
    AddModelCommand(std::shared_ptr<Object> model);

    virtual void exec() override;

private:
    std::shared_ptr<Object> _model;
};



class RemoveModelCommand : public ModelBaseCommand
{
public:
    RemoveModelCommand(std::size_t model_num);

    virtual void exec() override;

private:
    std::size_t _model_num;
};


class CountModelCommand : public ModelBaseCommand
{
public:
    CountModelCommand(const std::shared_ptr<size_t> &count);

    virtual void exec() override;

private:
    std::shared_ptr<size_t> _count;
};


class LoadModelCommand : public ModelBaseCommand
{
public:
    LoadModelCommand(std::string file_name);

    virtual void exec() override;

private:
    std::string _file_name;
};


class ExportModelCommand : public ModelBaseCommand
{
public:
    ExportModelCommand(std::string file_name);

    virtual void exec() override;

private:
    std::string _file_name;
};

#endif
