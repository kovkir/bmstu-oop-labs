#ifndef BASE_LOADER_MODEL_H
#define BASE_LOADER_MODEL_H

#include "base_loader.h"
#include "../builder/builder_model.h"

class BaseLoaderModel : public BaseLoader
{
public:
    virtual std::shared_ptr<Object> load(std::shared_ptr<BuilderModel> builder) = 0;
};

#endif
