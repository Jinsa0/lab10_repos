#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10_01_A/student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // 1. Перевірка підрахунку оцінок «5», «4», «3» з фізики на змішаному масиві
        TEST_METHOD(TestCountPhysicsGradesMixed)
        {
            const int N = 5;
            Student s[N] = {
                { "Іваненко", 1, KN,  5, 5, 4 },
                { "Петренко", 2, INF, 4, 3, 5 },
                { "Сидоренко", 1, ME, 3, 4, 4 },
                { "Коваленко", 3, FI, 5, 4, 5 },
                { "Бондаренко", 2, TN, 2, 5, 3 }
            };
            int c5 = -1, c4 = -1, c3 = -1;
            CountPhysicsGrades(s, N, c5, c4, c3);
            Assert::AreEqual(2, c5);
            Assert::AreEqual(1, c4);
            Assert::AreEqual(1, c3);
        }

        // 2. Перевірка CountPhysicsGrades(), коли немає оцінок «5», «4», «3»
        TEST_METHOD(TestCountPhysicsGradesNone)
        {
            const int N = 2;
            Student s[N] = {
                { "Мельник", 1, KN, 2, 3, 4 },
                { "Шевченко", 2, INF, 2, 2, 3 }
            };
            int c5 = -1, c4 = -1, c3 = -1;
            CountPhysicsGrades(s, N, c5, c4, c3);
            Assert::AreEqual(0, c5);
            Assert::AreEqual(0, c4);
            Assert::AreEqual(0, c3);
        }

        // 3. Перевірка CountGoodPhysicsAndMath(): обидві оцінки «4» або «5»
        TEST_METHOD(TestCountGoodPhysicsAndMathMixed)
        {
            const int N = 5;
            Student s[N] = {
                { "Іваненко", 1, KN,  5, 5, 3 }, // підходить
                { "Петренко", 2, INF, 4, 5, 4 }, // підходить
                { "Сидоренко", 1, ME, 4, 4, 5 }, // підходить
                { "Коваленко", 3, FI, 5, 3, 5 }, // не підходить (математика 3)
                { "Бондаренко", 2, TN, 3, 5, 4 } // не підходить (фізика 3)
            };
            Assert::AreEqual(3, CountGoodPhysicsAndMath(s, N));
        }

        // 4. Перевірка CountGoodPhysicsAndMath(), коли жоден студент не відповідає умові
        TEST_METHOD(TestCountGoodPhysicsAndMathZero)
        {
            const int N = 3;
            Student s[N] = {
                { "Ткаченко", 1, KN,  3, 3, 5 },
                { "Кравченко", 2, INF, 2, 5, 4 },
                { "Олійник", 3, ME,   5, 2, 4 }
            };
            Assert::AreEqual(0, CountGoodPhysicsAndMath(s, N));
        }
    };
}
