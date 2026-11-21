// ==================== lab10_01_B.cpp ====================
// lab10_01_B.cpp
// Кіц Роман Романович
// Лабораторна робота № 10.1 В
// Послідовний пошук в масиві структур.
// Варіант 12
#include <iostream>
#include <Windows.h> // забезпечення відображення кирилиці
#include "student.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;

    Student* s = new Student[N];

    Create(s, N);
    Print(s, N);

    int count5 = 0, count4 = 0, count3 = 0;
    CountPhysicsGrades(s, N, count5, count4, count3);
    cout << "Кількість оцінок з фізики:" << endl;
    cout << "  «5»: " << count5 << endl;
    cout << "  «4»: " << count4 << endl;
    cout << "  «3»: " << count3 << endl;

    int goodCount = CountGoodPhysicsAndMath(s, N);
    cout << "Кількість студентів, які отримали і з фізики і з математики оцінки «4» або «5»: "
        << goodCount << endl;

    delete[] s;
    return 0;
}
