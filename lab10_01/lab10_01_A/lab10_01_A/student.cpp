// ==================== student.cpp ====================
// student.cpp — реалізація функцій формування, виведення та опрацювання масиву структур (Рівень А)
#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;

const string specStr[] = {
    "Комп'ютерні науки",
    "Інформатика",
    "Математика та економіка",
    "Фізика та інформатика",
    "Трудове навчання"
};

void Create(Student* s, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.get();  // очищуємо буфер клавіатури – бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

        cout << "    прізвище: "; getline(cin, s[i].prizv);
        cout << "    курс: "; cin >> s[i].kurs;
        cout << "    спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, "
            << "2 - Математика та економіка, 3 - Фізика та інформатика, "
            << "4 - Трудове навчання): ";
        cin >> spec;
        s[i].spec = (Specialnist)spec;
        cout << "    оцінка з фізики: "; cin >> s[i].physics;
        cout << "    оцінка з математики: "; cin >> s[i].math;
        cout << "    оцінка з інформатики: "; cin >> s[i].informatics;
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

void CountPhysicsGrades(const Student* s, const int N, int& count5, int& count4, int& count3)
{
    count5 = 0;
    count4 = 0;
    count3 = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].physics == 5)
            count5++;
        else if (s[i].physics == 4)
            count4++;
        else if (s[i].physics == 3)
            count3++;
    }
}

int CountGoodPhysicsAndMath(const Student* s, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if ((s[i].physics == 4 || s[i].physics == 5) &&
            (s[i].math == 4 || s[i].math == 5))
        {
            k++;
        }
    }
    return k;
}
