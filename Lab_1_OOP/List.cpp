#include "List.h"

List::List() {
    std::cout << "List constructor\n";
}

List::~List() {
    std::cout << "List destructor\n";
}

char List::get_type() const {
    return 'L';
}
