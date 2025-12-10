#pragma once
#include "Base.h"
#include <stdexcept>

class Queue : public Base {
protected:
    int* data;
    int size;

public:
    Queue();
    virtual ~Queue();

    char get_type() const override;

    void input() override;
    void print() const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
};
