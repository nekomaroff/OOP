#include "Keeper.h"
#include <stdexcept>
#include <fstream>

Keeper::Keeper() : arr(nullptr), size(0) {
    std::cout << "Keeper constructor\n";
}

Keeper::~Keeper() {
    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;
    std::cout << "Keeper destructor\n";
}

void Keeper::add(Base* obj) {
    Base** temp = new Base*[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = arr[i];

    temp[size] = obj;

    delete[] arr;
    arr = temp;
    size++;

    std::cout << "Объект добавлен.\n";
}

void Keeper::remove(int index) {
    if (index < 0 || index >= size)
        throw std::runtime_error("Неверный индекс!");

    delete arr[index];

    Base** temp = new Base*[size - 1];

    for (int i = 0, j = 0; i < size; i++) {
        if (i == index) continue;
        temp[j++] = arr[i];
    }

    delete[] arr;
    arr = temp;
    size--;

    std::cout << "Объект удалён.\n";
}

void Keeper::print_all() const {
    std::cout << "Содержимое Keeper (" << size << " объектов):\n";
    for (int i = 0; i < size; i++) {
        std::cout << i << ") ";
        arr[i]->print();
    }
}

void Keeper::save_to_file(const std::string& path) const {
    std::ofstream out(path);
    if (!out.is_open())
        throw std::runtime_error("Ошибка открытия файла!");
    out << size << "\n";

    for (int i = 0; i < size; i++) {
        out << arr[i]->get_type() << " ";
        arr[i]->save(out);
    }
    std::cout << "Сохранено в файл: " << path << "\n";
}
void Keeper::load_from_file(const std::string& path) {
    std::ifstream in(path);
    if (!in.is_open())
        throw std::runtime_error("Ошибка открытия файла!");

    for (int i = 0; i < size; i++)
        delete arr[i];
    delete[] arr;

    in >> size;
    arr = new Base*[size];

    for (int i = 0; i < size; i++) {
        char type;
        in >> type;

        Base* obj = nullptr;

        if (type == 'Q') obj = new Queue();
        else if (type == 'S') obj = new Stack();
        else if (type == 'D') obj = new Deque();
        else if (type == 'L') obj = new List();
        else throw std::runtime_error("Неизвестный тип объекта в файле!");

        obj->load(in);
        arr[i] = obj;
    }

    std::cout << "Загружено из файла: " << path << "\\n";
}
