#pragma once
#include <iostream>
#include <fstream>

class Base {
public:
    virtual ~Base();

    virtual void input() = 0;
    virtual void print() const = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual void load(std::ifstream& in) = 0;

    virtual char get_type() const = 0;
};
