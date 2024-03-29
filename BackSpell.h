#pragma once

#include "AbstractBack.h"
#include <array>
#include <memory>

class BackSpell final : public AbstractBack
{

public:
    BackSpell();
    ~BackSpell() = default;
    bool update() override;
    void draw() const override;

private:

    class Quadrangle {
    public:
        const int img;
        float x, y;
        Quadrangle(float x, float y, int img) : x(x), y(y), img(img) {}
    };

    const static int NUM = 4;

    std::array<std::shared_ptr<Quadrangle>, NUM> _list;
};
