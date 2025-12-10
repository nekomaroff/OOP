#pragma once
#include <string>
#include "Base.h"
#include "Queue.h"
#include "Stack.h"
#include "Deque.h"
#include "List.h"

class Keeper {
private:
    Base** arr;
    int size;

public:
    Keeper();
    ~Keeper();

    void add(Base* obj);
    void remove(int index);
    void print_all() const;

    void save_to_file(const std::string& path) const;
    void load_from_file(const std::string& path);
};
