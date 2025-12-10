#pragma once
#include "Queue.h"

class Stack : public Queue {
public:
    Stack();
    ~Stack() override;

    char get_type() const override;
};
