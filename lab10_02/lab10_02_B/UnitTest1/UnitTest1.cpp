#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10_02_B/student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // 1. Перевірка фізичного впорядкування Sort() для структур з об'єднанням
        TEST_METHOD(TestPhysicalSortWithUnion)
        {
            const int N = 5;
            Student s[N];
            s[0] = { "Авраменко", 2, KN,  5, 5,{ 5 } };
            s[1] = { "Шевченко",  2, INF, 5, 4,{ 4 } };
            s[2] = { "Петренко",  1, ME,  5, 3,{ 4 } };
            s[3] = { "Бойко",     3, FI,  4, 4,{ 5 } };
            s[4] = { "Коваленко", 2, TN,  5, 5,{ 3 } };

            Sort(s, N);

            // Фізика (зрост.), курс (зрост.), прізвище (спад.)
            Assert::AreEqual(string("Бойко"), s[0].prizv);
            Assert::AreEqual(string("Петренко"), s[1].prizv);
            Assert::AreEqual(string("Шевченко"), s[2].prizv);
            Assert::AreEqual(string("Коваленко"), s[3].prizv);
            Assert::AreEqual(string("Авраменко"), s[4].prizv);

            // Перевірка збереження полів об'єднання після обміну структур
            Assert::AreEqual(5, s[0].pedagogy);
            Assert::AreEqual(4, s[2].numericalMethods);
            Assert::AreEqual(5, s[4].programming);
        }

        // 2. Перевірка індексного впорядкування IndexSort() для структур з об'єднанням
        TEST_METHOD(TestIndexSortWithUnion)
        {
            const int N = 5;
            Student s[N];
            s[0] = { "Шевченко",  2, INF, 5, 4,{ 4 } };
            s[1] = { "Авраменко", 2, KN,  5, 5,{ 5 } };
            s[2] = { "Петренко",  1, ME,  5, 3,{ 4 } };
            s[3] = { "Бойко",     3, FI,  4, 4,{ 5 } };
            s[4] = { "Коваленко", 2, TN,  5, 5,{ 3 } };

            int* I = IndexSort(s, N);

            // Основний масив незмінний
            Assert::AreEqual(string("Шевченко"), s[0].prizv);
            Assert::AreEqual(string("Авраменко"), s[1].prizv);

            // Індексний порядок: фізика (зрост.), курс (зрост.), прізвище (зрост.)
            Assert::AreEqual(3, I[0]); // Бойко (4, 3)
            Assert::AreEqual(2, I[1]); // Петренко (5, 1)
            Assert::AreEqual(1, I[2]); // Авраменко (5, 2)
            Assert::AreEqual(4, I[3]); // Коваленко (5, 2)
            Assert::AreEqual(0, I[4]); // Шевченко (5, 2)

            delete[] I;
        }

        // 3. Перевірка бінарного пошуку BinSearch() — елемент знайдено
        TEST_METHOD(TestBinSearchFoundWithUnion)
        {
            const int N = 5;
            Student s[N];
            s[0] = { "Авраменко", 2, KN,  5, 5,{ 5 } };
            s[1] = { "Шевченко",  2, INF, 5, 4,{ 4 } };
            s[2] = { "Петренко",  1, ME,  5, 3,{ 4 } };
            s[3] = { "Бойко",     3, FI,  4, 4,{ 5 } };
            s[4] = { "Коваленко", 2, TN,  5, 5,{ 3 } };

            Sort(s, N);

            Assert::AreEqual(0, BinSearch(s, N, "Бойко", 3, 4));
            Assert::AreEqual(1, BinSearch(s, N, "Петренко", 1, 5));
            Assert::AreEqual(3, BinSearch(s, N, "Коваленко", 2, 5));
            Assert::AreEqual(4, BinSearch(s, N, "Авраменко", 2, 5));
        }

        // 4. Перевірка бінарного пошуку BinSearch() — елемент відсутній
        TEST_METHOD(TestBinSearchNotFoundWithUnion)
        {
            const int N = 3;
            Student s[N];
            s[0] = { "Бойко",    3, FI,  4, 4,{ 5 } };
            s[1] = { "Петренко", 1, ME,  5, 3,{ 4 } };
            s[2] = { "Шевченко", 2, INF, 5, 4,{ 4 } };

            Sort(s, N);

            Assert::AreEqual(-1, BinSearch(s, N, "Мельник", 2, 5));
            Assert::AreEqual(-1, BinSearch(s, N, "Бойко", 2, 4));
            Assert::AreEqual(-1, BinSearch(s, N, "Петренко", 1, 3));
        }
    };
}
