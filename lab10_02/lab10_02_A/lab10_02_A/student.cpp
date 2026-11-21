// ==================== student.cpp ====================
// student.cpp — реалізація функцій формування, виведення, фізичного й індексного впорядкування та бінарного пошуку (Рівень А)
#include "student.h"
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const string specStr[] = {
    "Комп'ютерні науки",
    "Інформатика",
    "Математика та економіка",
    "Фізика та інформатика",
    "Трудове навчання"
};

int ReadIntInRange(const string& prompt, int minVal, int maxVal)
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка введення! Введіть ціле число в діапазоні ["
                << minVal << "; " << maxVal << "]." << endl;
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void Create(Student* s, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        do
        {
            cout << "    прізвище: ";
            getline(cin, s[i].prizv);
            if (s[i].prizv.empty())
                cout << "Помилка! Прізвище не може бути порожнім." << endl;
        } while (s[i].prizv.empty());

        s[i].kurs = ReadIntInRange("    курс (1-6): ", 1, 6);
        spec = ReadIntInRange(
            "    спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, "
            "2 - Математика та економіка, 3 - Фізика та інформатика, "
            "4 - Трудове навчання): ", 0, 4);
        s[i].spec = (Specialnist)spec;
        s[i].physics = ReadIntInRange("    оцінка з фізики (1-5): ", 1, 5);
        s[i].math = ReadIntInRange("    оцінка з математики (1-5): ", 1, 5);
        s[i].informatics = ReadIntInRange("    оцінка з інформатики (1-5): ", 1, 5);
        cout << endl;
    }
}

void Print(const Student* s, const int N)
{
    cout << "Список студентів (Рівень А):" << endl;
    cout << "============================================================================================="
        << endl;
    cout << "|  №  |   Прізвище    | Курс |      Спеціальність       | Фізика | Математика | Інформатика |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " "
            << "| " << setw(13) << left << s[i].prizv << " "
            << "| " << setw(4) << right << s[i].kurs << " "
            << "| " << setw(24) << left << specStr[s[i].spec] << " "
            << "| " << setw(6) << right << s[i].physics << " "
            << "| " << setw(10) << right << s[i].math << " "
            << "| " << setw(11) << right << s[i].informatics << " |" << endl;
    }

    cout << "============================================================================================="
        << endl;
    cout << endl;
}

void Sort(Student* s, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((s[i1].physics > s[i1 + 1].physics)
                ||
                (s[i1].physics == s[i1 + 1].physics &&
                    s[i1].kurs > s[i1 + 1].kurs)
                ||
                (s[i1].physics == s[i1 + 1].physics &&
                    s[i1].kurs == s[i1 + 1].kurs &&
                    s[i1].prizv < s[i1 + 1].prizv))
            {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
}

int* IndexSort(const Student* s, const int N)
{
    // використовуємо метод вставки для формування індексного масиву
    int* I = new int[N]; // створили індексний масив

    for (int i = 0; i < N; i++)
        I[i] = i;        // заповнили його початковими даними

    int i, j, value;     // починаємо сортувати масив індексів
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((s[I[j]].physics > s[value].physics) ||
                (s[I[j]].physics == s[value].physics &&
                    s[I[j]].kurs > s[value].kurs) ||
                (s[I[j]].physics == s[value].physics &&
                    s[I[j]].kurs == s[value].kurs &&
                    s[I[j]].prizv > s[value].prizv));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }

    return I;
}

void PrintIndexSorted(const Student* s, const int* I, const int N)
{
    // аналогічно функції Print(), але доступ через індексний масив I: s[I[i]]
    cout << "Індексно впорядкований список студентів (Рівень А):" << endl;
    cout << "============================================================================================="
        << endl;
    cout << "|  №  |   Прізвище    | Курс |      Спеціальність       | Фізика | Математика | Інформатика |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1 << " "
            << "| " << setw(13) << left << s[I[i]].prizv << " "
            << "| " << setw(4) << right << s[I[i]].kurs << " "
            << "| " << setw(24) << left << specStr[s[I[i]].spec] << " "
            << "| " << setw(6) << right << s[I[i]].physics << " "
            << "| " << setw(10) << right << s[I[i]].math << " "
            << "| " << setw(11) << right << s[I[i]].informatics << " |" << endl;
    }

    cout << "============================================================================================="
        << endl;
    cout << endl;
}

int BinSearch(const Student* s, const int N, const string prizv, const int kurs, const int physics)
{
    // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
    if (N <= 0)
        return -1;

    int L = 0, R = N - 1, m;
    do
    {
        m = (L + R) / 2;
        if (s[m].prizv == prizv && s[m].kurs == kurs && s[m].physics == physics)
            return m;
        if ((s[m].physics < physics)
            ||
            (s[m].physics == physics &&
                s[m].kurs < kurs)
            ||
            (s[m].physics == physics &&
                s[m].kurs == kurs &&
                s[m].prizv > prizv))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}