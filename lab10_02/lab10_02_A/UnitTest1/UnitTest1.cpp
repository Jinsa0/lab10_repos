#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10_02_A/student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // 1. Перевірка фізичного впорядкування Sort(): фізика (зрост.), курс (зрост.), прізвище (спад.)
        TEST_METHOD(TestPhysicalSortOrder)
        {
            const int N = 5;
            Student s[N] = {
                { "Авраменко", 2, KN,  5, 5, 5 },
                { "Шевченко",  2, INF, 5, 4, 4 },
                { "Петренко",  1, ME,  5, 3, 4 },
                { "Бойко",     3, FI,  4, 4, 5 },
                { "Коваленко", 2, TN,  5, 5, 3 }
            };

            Sort(s, N);

            // Очікуваний порядок:
            // [0] Бойко (фізика 4, курс 3)
            // [1] Петренко (фізика 5, курс 1)
            // [2] Шевченко (фізика 5, курс 2, прізвище за спаданням)
            // [3] Коваленко (фізика 5, курс 2)
            // [4] Авраменко (фізика 5, курс 2)
            Assert::AreEqual(string("Бойко"), s[0].prizv);
            Assert::AreEqual(string("Петренко"), s[1].prizv);
            Assert::AreEqual(string("Шевченко"), s[2].prizv);
            Assert::AreEqual(string("Коваленко"), s[3].prizv);
            Assert::AreEqual(string("Авраменко"), s[4].prizv);
        }

        // 2. Перевірка індексного впорядкування IndexSort(): фізика (зрост.), курс (зрост.), прізвище (зрост.)
        TEST_METHOD(TestIndexSortOrderAndImmutability)
        {
            const int N = 5;
            Student s[N] = {
                { "Шевченко",  2, INF, 5, 4, 4 }, // 0
                { "Авраменко", 2, KN,  5, 5, 5 }, // 1
                { "Петренко",  1, ME,  5, 3, 4 }, // 2
                { "Бойко",     3, FI,  4, 4, 5 }, // 3
                { "Коваленко", 2, TN,  5, 5, 3 }  // 4
            };

            int* I = IndexSort(s, N);

            // Основний масив не повинен змінитися
            Assert::AreEqual(string("Шевченко"), s[0].prizv);
            Assert::AreEqual(string("Бойко"), s[3].prizv);

            // Очікуваний порядок через індекси:
            // 3 (Бойко, 4, 3), 2 (Петренко, 5, 1), 1 (Авраменко, 5, 2), 4 (Коваленко, 5, 2), 0 (Шевченко, 5, 2)
            Assert::AreEqual(3, I[0]);
            Assert::AreEqual(2, I[1]);
            Assert::AreEqual(1, I[2]);
            Assert::AreEqual(4, I[3]);
            Assert::AreEqual(0, I[4]);

            delete[] I;
        }

        // 3. Перевірка бінарного пошуку BinSearch() — елемент присутній у масиві
        TEST_METHOD(TestBinSearchFound)
        {
            const int N = 5;
            Student s[N] = {
                { "Авраменко", 2, KN,  5, 5, 5 },
                { "Шевченко",  2, INF, 5, 4, 4 },
                { "Петренко",  1, ME,  5, 3, 4 },
                { "Бойко",     3, FI,  4, 4, 5 },
                { "Коваленко", 2, TN,  5, 5, 3 }
            };

            Sort(s, N);

            Assert::AreEqual(0, BinSearch(s, N, "Бойко", 3, 4));
            Assert::AreEqual(2, BinSearch(s, N, "Шевченко", 2, 5));
            Assert::AreEqual(4, BinSearch(s, N, "Авраменко", 2, 5));
        }

        // 4. Перевірка бінарного пошуку BinSearch() — елемент відсутній (невідповідність ключів)
        TEST_METHOD(TestBinSearchNotFound)
        {
            const int N = 4;
            Student s[N] = {
                { "Бойко",     3, FI,  4, 4, 5 },
                { "Петренко",  1, ME,  5, 3, 4 },
                { "Шевченко",  2, INF, 5, 4, 4 },
                { "Авраменко", 2, KN,  5, 5, 5 }
            };

            Sort(s, N);

            Assert::AreEqual(-1, BinSearch(s, N, "Неіснуючий", 2, 5));
            Assert::AreEqual(-1, BinSearch(s, N, "Шевченко", 1, 5)); // інший курс
            Assert::AreEqual(-1, BinSearch(s, N, "Шевченко", 2, 4)); // інша оцінка з фізики
        }
    };
}
