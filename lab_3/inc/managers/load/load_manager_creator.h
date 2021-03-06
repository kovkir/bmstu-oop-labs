#ifndef LOAD_MANAGER_CREATOR_H
#define LOAD_MANAGER_CREATOR_H

#include <memory>

#include "load_manager.h"

class CreatorLoadManager
{
public:
    std::shared_ptr<LoadManager> create_manager();
    std::shared_ptr<LoadManager> create_manager(const std::shared_ptr<AbstractLoadController> &loader);

private:
    void create_instance();

    std::shared_ptr<LoadManager> _manager;
};

#endif
