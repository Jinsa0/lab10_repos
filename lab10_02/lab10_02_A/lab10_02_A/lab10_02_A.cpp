// ==================== lab10_02_A.cpp ====================
// lab10_02_A.cpp
// Кіц Роман Романович
// Лабораторна робота № 10.2 А
// Впорядкування та бінарний пошук в масиві структур.
// Варіант 12
#include <iostream>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
#include "student.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N = ReadIntInRange("Введіть кількість студентів N (1-1000): ", 1, 1000);
    Student* s = new Student[N];

    bool isCreated = false;
    bool isSorted = false;
    string prizv;
    int kurs, physics, found;
    int* I = nullptr;

    int menuItem;
    do
    {
        cout << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << "  [1] - введення даних з клавіатури" << endl;
        cout << "  [2] - вивід даних на екран" << endl;
        cout << "  [3] - фізичне впорядкування даних" << endl;
        cout << "  [4] - індексне впорядкування та вивід даних" << endl;
        cout << "  [5] - бінарний пошук студента за оцінкою з фізики, курсом та прізвищем"
            << endl << endl;
        cout << "  [0] - вихід та завершення роботи програми" << endl << endl;
        menuItem = ReadIntInRange("Введіть значення: ", 0, 5);
        cout << endl;

        switch (menuItem)
        {
        case 1:
            Create(s, N);
            isCreated = true;
            isSorted = false;
            break;
        case 2:
            if (!isCreated)
                cout << "Спочатку введіть дані (пункт меню [1])!" << endl;
            else
                Print(s, N);
            break;
        case 3:
            if (!isCreated)
                cout << "Спочатку введіть дані (пункт меню [1])!" << endl;
            else
            {
                Sort(s, N);
                isSorted = true;
                cout << "Масив фізично впорядковано." << endl;
            }
            break;
        case 4:
            if (!isCreated)
                cout << "Спочатку введіть дані (пункт меню [1])!" << endl;
            else
            {
                I = IndexSort(s, N);
                PrintIndexSorted(s, I, N);
                delete[] I;
                I = nullptr;
            }
            break;
        case 5:
            if (!isCreated)
            {
                cout << "Спочатку введіть дані (пункт меню [1])!" << endl;
                break;
            }
            if (!isSorted)
            {
                cout << "Для бінарного пошуку спочатку виконайте фізичне впорядкування (пункт [3])!" << endl;
                break;
            }
            cout << "Введіть ключі пошуку:" << endl;
            physics = ReadIntInRange("    оцінка з фізики (1-5): ", 1, 5);
            kurs = ReadIntInRange("    курс (1-6): ", 1, 6);
            cout << "    прізвище: ";
            getline(cin, prizv);
            cout << endl;
            if ((found = BinSearch(s, N, prizv, kurs, physics)) != -1)
                cout << "Знайдено студента в позиції " << found + 1 << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    delete[] s;
    return 0;
}
