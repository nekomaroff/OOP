#pragma once
#include "Queue.h"

class List : public Queue {
public:
    List();
    ~List() override;

    char get_type() const override;
};
