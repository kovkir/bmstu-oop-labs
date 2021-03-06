#ifndef BUILDER_SCENE_H
#define BUILDER_SCENE_H

#include "../scene/scene.h"
#include "base_builder.h"

class BuilderScene : public BaseBuilder
{
public:
    BuilderScene() = default;
    ~BuilderScene() = default;

    void build() override;
    void build_model(const std::shared_ptr<Object> &object);
    void build_camera(const std::shared_ptr<Camera> &camera);

    bool is_build() const override;

    std::shared_ptr<Object> get() override;

private:
    std::shared_ptr<Scene> _scene_ptr;
};

#endif
