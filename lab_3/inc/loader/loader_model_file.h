#ifndef MODEL_LOADER_FILE_H
#define MODEL_LOADER_FILE_H

#include "base_loader_model.h"

class ModelLoaderFile : public BaseLoaderModel
{
public:
    ModelLoaderFile();
    explicit ModelLoaderFile(std::shared_ptr<std::ifstream> &file_in);
    ~ModelLoaderFile() override = default;

    void open(std::string &file_name) override;
    void close() override;

    std::shared_ptr<Object> load(std::shared_ptr<BuilderModel> builder) override;

protected:
    std::shared_ptr<std::ifstream> _file;
};

#endif
