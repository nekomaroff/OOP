#pragma once
#include "Queue.h"

class Deque : public Queue {
public:
    Deque();
    ~Deque() override;

    char get_type() const override;
};
