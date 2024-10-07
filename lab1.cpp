#include <iostream>
#include <string>
#include <fstream>
#include <limits>

// Структура для представления трубы
struct Труба {
    std::string название;
    double длина;
    double диаметр;
    bool вРемонте;

    // Ввод данных о трубе с проверками
    void ввод() {
        std::cout << "Введите название трубы: ";
        std::cin.ignore();
        std::getline(std::cin, название);

        std::cout << "Введите длину трубы: ";
        while (!(std::cin >> длина) || длина < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Длина не может быть отрицательной." << std::endl;
            }
            std::cout << "Введите длину трубы: ";
        }

        std::cout << "Введите диаметр трубы: ";
        while (!(std::cin >> диаметр) || диаметр < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Диаметр не может быть отрицательным." << std::endl;
            }
            std::cout << "Введите диаметр трубы: ";
        }

        std::cout << "Находится ли труба в ремонте? (1 - да, 0 - нет): ";
        std::cin >> вРемонте;
    }

    // Вывод данных о трубе
    void вывод() const {
        std::cout << "Название трубы: " << название << std::endl;
        std::cout << "Длина: " << длина << " км" << std::endl;
        std::cout << "Диаметр: " << диаметр << " м" << std::endl;
        std::cout << "В ремонте: " << (вРемонте ? "Да" : "Нет") << std::endl;
    }

    // Редактирование признака "в ремонте"
    void изменитьСтатусРемонта() {
        std::cout << "Введите новый статус ремонта (1 - да, 0 - нет): ";
        std::cin >> вРемонте;
    }
};

// Структура для представления компрессорной станции (КС)
struct КомпрессорнаяСтанция {
    std::string название;
    int общееКолВоЦехов;
    int активныеЦеха;
    double эффективность;

    // Ввод данных о КС с проверками
    void ввод() {
        std::cout << "Введите название станции: ";
        std::cin.ignore();
        std::getline(std::cin, название);

        std::cout << "Введите общее количество цехов: ";
        while (!(std::cin >> общееКолВоЦехов) || общееКолВоЦехов < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Целые значения вводятся без запятой." << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Количество не может быть отрицательным." << std::endl;
            }
            std::cout << "Введите общее количество цехов: ";
        }

        std::cout << "Введите количество активных цехов: ";
        while (!(std::cin >> активныеЦеха) || активныеЦеха > общееКолВоЦехов || активныеЦеха < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Целые значения вводятся без запятой." << std::endl;
            } else {
                std::cout << "Активные цеха не могут превышать общее количество или быть меньше 0." << std::endl;
            }
            std::cout << "Введите количество активных цехов: ";
        }

        std::cout << "Введите эффективность станции: ";
        while (!(std::cin >> эффективность) || эффективность < 0) {
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Введены неправильные значения. Десятичные дроби вводятся через точку, например: 0.1" << std::endl;
            } else {
                std::cout << "Перепроверьте значения. Эффективность не может быть отрицательной." << std::endl;
            }
            std::cout << "Введите эффективность станции: ";
        }
    }

    // Вывод данных о КС
    void вывод() const {
        std::cout << "Название станции: " << название << std::endl;
        std::cout << "Общее количество цехов: " << общееКолВоЦехов << std::endl;
        std::cout << "Активные цеха: " << активныеЦеха << std::endl;
        std::cout << "Эффективность: " << эффективность << std::endl;
    }

    // Запуск цеха
    void запуститьЦех() {
        if (активныеЦеха < общееКолВоЦехов) {
            активныеЦеха++;
            std::cout << "Цех запущен. Активные цеха: " << активныеЦеха << std::endl;
        } else {
            std::cout << "Все цеха уже активны." << std::endl;
        }
    }

    // Остановка цеха
    void остановитьЦех() {
        if (активныеЦеха > 0) {
            активныеЦеха--;
            std::cout << "Цех остановлен. Активные цеха: " << активныеЦеха << std::endl;
        } else {
            std::cout << "Нет активных цехов для остановки." << std::endl;
        }
    }
};

// Функции для сохранения и загрузки данных в файл
void сохранитьВФайл(Труба трубы[], int колТруб, КомпрессорнаяСтанция станции[], int колСтанций) {
    std::ofstream файл("данные.txt");
    if (!файл.is_open()) {
        std::cerr << "Ошибка открытия файла для сохранения!" << std::endl;
        return;
    }

    файл << колТруб << std::endl;
    for (int i = 0; i < колТруб; i++) {
        файл << трубы[i].название
             << std::endl << трубы[i].длина
             << std::endl << трубы[i].диаметр
             << std::endl << трубы[i].вРемонте << std::endl;
    }

    файл << колСтанций << std::endl;
    for (int i = 0; i < колСтанций; i++) {
        файл << станции[i].название
             << std::endl << станции[i].общееКолВоЦехов
             << std::endl << станции[i].активныеЦеха
             << std::endl << станции[i].эффективность << std::endl;
    }

    файл.close();
    std::cout << "Данные успешно сохранены." << std::endl;
}

void загрузитьИзФайла(Труба трубы[], int &колТруб, КомпрессорнаяСтанция станции[], int &колСтанций) {
    std::ifstream файл("данные.txt");
    if (!файл.is_open()) {
        std::cerr << "Ошибка открытия файла для загрузки!" << std::endl;
        return;
    }

    файл >> колТруб;
    файл.ignore();
    for (int i = 0; i < колТруб; i++) {
        std::getline(файл, трубы[i].название);
        файл >> трубы[i].длина >> трубы[i].диаметр >> трубы[i].вРемонте;
        файл.ignore();
    }

    файл >> колСтанций;
    файл.ignore();
    for (int i = 0; i < колСтанций; i++) {
        std::getline(файл, станции[i].название);
        файл >> станции[i].общееКолВоЦехов >> станции[i].активныеЦеха >> станции[i].эффективность;
        файл.ignore();
    }

    файл.close();
    std::cout << "Данные успешно загружены." << std::endl;
}

int main() {
    Труба трубы[100];
    КомпрессорнаяСтанция станции[100];
    int колТруб = 0, колСтанций = 0;
    int выбор;

    while (true) {
        std::cout << "1. Добавить трубу" << std::endl;
        std::cout << "2. Добавить компрессорную станцию" << std::endl;
        std::cout << "3. Просмотреть все объекты" << std::endl;
        std::cout << "4. Изменить статус ремонта трубы" << std::endl;
        std::cout << "5. Запустить/остановить цех" << std::endl;
        std::cout << "6. Сохранить" << std::endl;
        std::cout << "7. Загрузить" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> выбор;

        if (выбор == 0) {
            break;
        }

        switch (выбор) {
            case 1: {
                трубы[колТруб].ввод();
                колТруб++;
                break;
            }
            case 2: {
                станции[колСтанций].ввод();
                колСтанций++;
                break;
            }
            case 3: {
                if (колТруб == 0) {
                    std::cout << "Нет труб." << std::endl;
                } else {
                    for (int i = 0; i < колТруб; i++) {
                        трубы[i].вывод();
                        std::cout << "----------------------" << std::endl;
                    }
                }
                if (колСтанций == 0) {
                    std::cout << "Нет компрессорных станций." << std::endl;
                } else {
                    for (int i = 0; i < колСтанций; i++) {
                        станции[i].вывод();
                        std::cout << "----------------------" << std::endl;
                    }
                }
                break;
            }
            case 4: {
                std::cout << "Введите индекс трубы для редактирования: ";
                int индекс;
                std::cin >> индекс;
                if (индекс < колТруб && индекс >= 0) {
                    трубы[индекс].изменитьСтатусРемонта();
                } else {
                    std::cerr << "Неверный индекс." << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Введите индекс компрессорной станции для редактирования: ";
                int индекс;
                std::cin >> индекс;
                if (индекс < колСтанций && индекс >= 0) {
                    std::cout << "1. Запустить цех" << std::endl;
                    std::cout << "2. Остановить цех" << std::endl;
                    std::cout << "Выберите действие: ";
                    int действие;
                    std::cin >> действие;
                    if (действие == 1) {
                        станции[индекс].запуститьЦех();
                    } else if (действие == 2) {
                        станции[индекс].остановитьЦех();
                    } else {
                        std::cerr << "Неверное действие." << std::endl;
                    }
                } else {
                    std::cerr << "Неверный индекс." << std::endl;
                }
                break;
            }
            case 6: {
                сохранитьВФайл(трубы, колТруб, станции, колСтанций);
                break;
            }
            case 7: {
                загрузитьИзФайла(трубы, колТруб, станции, колСтанций);
                break;
            }
            default:
                std::cerr << "Неверная опция. Попробуйте снова." << std::endl;
        }
    }

    return 0;
}
