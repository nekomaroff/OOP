#include "Stack.h"

Stack::Stack() {
    std::cout << "Stack constructor\n";
}

Stack::~Stack() {
    std::cout << "Stack destructor\n";
}

char Stack::get_type() const {
    return 'S';
}
