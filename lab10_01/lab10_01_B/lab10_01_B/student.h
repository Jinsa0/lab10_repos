// ==================== student.h ====================
// student.h — оголошення переліку спеціальностей, структури Student з об'єднанням (Рівень В) та прототипів функцій
#pragma once
#include <string>
using namespace std;

enum Specialnist { KN, INF, ME, FI, TN };

extern const string specStr[];

struct Student
{
    string prizv;
    int kurs;
    Specialnist spec;
    int physics;
    int math;
    union
    {
        int programming;
        int numericalMethods;
        int pedagogy;
    };
};

void Create(Student* s, const int N);
void Print(const Student* s, const int N);
void CountPhysicsGrades(const Student* s, const int N, int& count5, int& count4, int& count3);
int CountGoodPhysicsAndMath(const Student* s, const int N);
