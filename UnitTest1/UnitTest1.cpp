#include "pch.h"
#include "CppUnitTest.h"
#include <string.h>
//#define _CRT_SECURE_NO_WARININGS
extern "C" {
#include "../RPS/utils.h"
}
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include <string>
#include <cstring>

void rock_paper_scissors(const char* player1, const char* player2, char* result) {
    std::string p1(player1);
    std::string p2(player2);

    if ((p1 != "Rock" && p1 != "Paper" && p1 != "Scissors") ||
        (p2 != "Rock" && p2 != "Paper" && p2 != "Scissors")) {
        std::strcpy(result, "Invalid");
        return;
    }

    if (p1 == p2) {
        std::strcpy(result, "Draw");
    }
    else if ((p1 == "Rock" && p2 == "Scissors") ||
        (p1 == "Scissors" && p2 == "Paper") ||
        (p1 == "Paper" && p2 == "Rock")) {
        std::strcpy(result, "Player1");
    }
    else {
        std::strcpy(result, "Player2");
    }
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