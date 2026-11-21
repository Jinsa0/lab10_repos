#include "pch.h"
#include "CppUnitTest.h"
#include "../lab10_01_B/student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        // 1. Перевірка підрахунку оцінок «5», «4», «3» з фізики для структур з об'єднанням
        TEST_METHOD(TestCountPhysicsGradesWithUnion)
        {
            const int N = 5;
            Student s[N];
            s[0] = { "Іваненко",   1, KN,  5, 5,{ 5 } };
            s[1] = { "Петренко",   2, INF, 4, 4,{ 4 } };
            s[2] = { "Сидоренко",  1, ME,  3, 5,{ 4 } };
            s[3] = { "Коваленко",  3, FI,  4, 3,{ 5 } };
            s[4] = { "Бондаренко", 2, TN,  5, 4,{ 3 } };

            int c5 = -1, c4 = -1, c3 = -1;
            CountPhysicsGrades(s, N, c5, c4, c3);
            Assert::AreEqual(2, c5);
            Assert::AreEqual(2, c4);
            Assert::AreEqual(1, c3);
        }

        // 2. Перевірка CountPhysicsGrades() при всіх оцінках «3»
        TEST_METHOD(TestCountPhysicsGradesAllThrees)
        {
            const int N = 3;
            Student s[N];
            s[0] = { "Мельник",  1, KN,  3, 4,{ 5 } };
            s[1] = { "Шевченко", 2, INF, 3, 5,{ 4 } };
            s[2] = { "Ткаченко", 3, ME,  3, 3,{ 3 } };

            int c5 = -1, c4 = -1, c3 = -1;
            CountPhysicsGrades(s, N, c5, c4, c3);
            Assert::AreEqual(0, c5);
            Assert::AreEqual(0, c4);
            Assert::AreEqual(3, c3);
        }

        // 3. Перевірка CountGoodPhysicsAndMath() для різних спеціальностей
        TEST_METHOD(TestCountGoodPhysicsAndMathMixed)
        {
            const int N = 5;
            Student s[N];
            s[0] = { "Іваненко",   1, KN,  5, 5,{ 5 } }; // підходить
            s[1] = { "Петренко",   2, INF, 4, 4,{ 3 } }; // підходить
            s[2] = { "Сидоренко",  1, ME,  5, 4,{ 4 } }; // підходить
            s[3] = { "Коваленко",  3, FI,  4, 3,{ 5 } }; // не підходить
            s[4] = { "Бондаренко", 2, TN,  2, 5,{ 4 } }; // не підходить

            Assert::AreEqual(3, CountGoodPhysicsAndMath(s, N));
        }

        // 4. Перевірка спільного використання пам'яті в анонімному об'єднанні
        TEST_METHOD(TestUnionThirdGradeStorage)
        {
            Student st;
            st.prizv = "Кравченко";
            st.kurs = 2;
            st.spec = KN;
            st.physics = 5;
            st.math = 5;
            st.programming = 5;
            Assert::AreEqual(5, st.programming);

            st.spec = INF;
            st.numericalMethods = 4;
            Assert::AreEqual(4, st.numericalMethods);

            st.spec = TN;
            st.pedagogy = 3;
            Assert::AreEqual(3, st.pedagogy);
        }
    };
}
