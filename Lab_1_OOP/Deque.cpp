#include "Deque.h"

Deque::Deque() {
    std::cout << "Deque constructor\n";
}

Deque::~Deque() {
    std::cout << "Deque destructor\n";
}

char Deque::get_type() const {
    return 'D';
}
