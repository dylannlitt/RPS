#include "pch.h"
#include "CppUnitTest.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void rock_paper_scissors(const char* player1, const char* player2, char* result);
void rock_paper_scissors(const char* player1, const char* player2, char* result) {

}

namespace UnitTest1
{

    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestInvalidInput)
        {
            char result[10];
            rock_paper_scissors("Lizard", "Paper", result);
            Assert::AreEqual("Invalid", result);

            rock_paper_scissors("Rock", "Banana", result);
            Assert::AreEqual("Invalid", result);
        }

        TEST_METHOD(TestRockBeatsScissors)
        {
            char result[10];
            rock_paper_scissors("Rock", "Scissors", result);
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(TestScissorsBeatsPaper)
        {
            char result[10];
            rock_paper_scissors("Scissors", "Paper", result);
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(TestPaperBeatsRock)
        {
            char result[10];
            rock_paper_scissors("Paper", "Rock", result);
            Assert::AreEqual("Player1", result);
        }

        TEST_METHOD(TestDraw)
        {
            char result[10];
            rock_paper_scissors("Rock", "Rock", result);
            Assert::AreEqual("Draw", result);

            rock_paper_scissors("Paper", "Paper", result);
            Assert::AreEqual("Draw", result);

            rock_paper_scissors("Scissors", "Scissors", result);
            Assert::AreEqual("Draw", result);
        }

    };
}