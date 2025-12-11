#include "Menu.h"
#include <limits>

void Menu::run() {
    Keeper keeper;

    std::string filepath = "/Users/viacheslavkomarov/Desktop/data_oop_lab1.txt";

    while (true) {

        std::cout << "\n===== МЕНЮ =====\n";
        std::cout << "1) Добавить объект\n";
        std::cout << "2) Удалить объект\n";
        std::cout << "3) Показать все объекты\n";
        std::cout << "4) Сохранить в файл\n";
        std::cout << "5) Загрузить из файла\n";
        std::cout << "0) Выход\nВаш выбор: ";

        int choice;
        std::cin >> choice;

        if (!std::cin || choice < 0 || choice > 5) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Попробуйте снова.\n";
            continue;
        }
      

        if (choice == 1) {
            std::cout << "Выберите тип объекта:\n"
                      << "1) Queue\n2) Stack\n3) Deque\n4) List\nВаш выбор: ";

            int t;
            std::cin >> t;

            if (!std::cin || t < 1 || t > 4) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный ввод типа объекта.\n";
                continue;
            }

            Base* obj = nullptr;

            if (t == 1) obj = new Queue();
            else if (t == 2) obj = new Stack();
            else if (t == 3) obj = new Deque();
            else if (t == 4) obj = new List();

            obj->input();
            keeper.add(obj);
        }

        else if (choice == 2) {
            std::cout << "Введите индекс: ";
            int i;
            std::cin >> i;

            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Некорректный индекс.\n";
                continue;
            }

            try {
                keeper.remove(i);
            } catch (const std::exception& ex) {
                std::cout << "Исключение: " << ex.what() << "\n";
            }
        }

        else if (choice == 3) {
            keeper.print_all();
        }

        else if (choice == 4) {
            try {
                keeper.save_to_file(filepath);
                std::cout << "Сохранено.\n";
            } catch (const std::exception& ex) {
                std::cout << "Исключение: " << ex.what() << "\n";
            }
        }

        else if (choice == 5) {
            try {
                keeper.load_from_file(filepath);
                std::cout << "Файл загружен.\n";
            } catch (const std::exception& ex) {
                std::cout << "Исключение: " << ex.what() << "\n";
            }
        }

        else if (choice == 0) { 
            std::cout << "Выход...\n";
            break;
        }
    }
}
