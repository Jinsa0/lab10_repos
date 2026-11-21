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

int ReadIntInRange(const string& prompt, int minVal, int maxVal);
void Create(Student* s, const int N);
void Print(const Student* s, const int N);
void Sort(Student* s, const int N);
int* IndexSort(const Student* s, const int N);
void PrintIndexSorted(const Student* s, const int* I, const int N);
int BinSearch(const Student* s, const int N, const string prizv, const int kurs, const int physics);
