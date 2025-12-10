#include "Queue.h"

Queue::Queue() : data(nullptr), size(0) {
    std::cout << "Queue default constructor\n";
}

Queue::~Queue() {
    delete[] data;
    std::cout << "Queue destructor\n";
}

char Queue::get_type() const {
    return 'Q';
}

void Queue::input() {
    std::cout << "Ввод очереди (только числа)\nВведите количество элементов: ";
    std::cin >> size;
    if (size <= 0) throw std::runtime_error("Ошибка ввода!");

    delete[] data;
    data = new int[size];

    std::cout << "Введите " << size << " чисел: ";
    for (int i = 0; i < size; i++)
        std::cin >> data[i];
}

void Queue::print() const {
    std::cout << "Очередь (" << size << " элементов): ";
    for (int i = 0; i < size; i++)
        std::cout << data[i] << " ";
    std::cout << "\n";
}

void Queue::save(std::ofstream& out) const {
    out << size << " ";
    for (int i = 0; i < size; i++)
        out << data[i] << " ";
    out << "\n";
}

void Queue::load(std::ifstream& in) {
    in >> size;
    delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++)
        in >> data[i];
}
