
#include <gtest/gtest.h>

#include "example.h"


class BowlingCalculatorTest : public ::testing::Test {
protected:
    BowlingCalculator calculator;
};

TEST_F(BowlingCalculatorTest, EmptyGame)
{
    for (int i = 0; i < 20; i++) {
        calculator.roll(0);
    }
    EXPECT_EQ(0, calculator.totalScore());
}

TEST_F(BowlingCalculatorTest, AllOnes)
{
    for (int i = 0; i < 20; i++) {
        calculator.roll(1);
    }
    EXPECT_EQ(20, calculator.totalScore());
}

TEST_F(BowlingCalculatorTest, OneSpare)
{
    calculator.roll(5);
    calculator.roll(5);
    calculator.roll(3);
    for (int i = 0; i < 17; i++) {
        calculator.roll(0);
    }
    EXPECT_EQ(16, calculator.totalScore());
}

TEST_F(BowlingCalculatorTest, OneStrike)
{
    calculator.roll(10);
    calculator.roll(3);
    calculator.roll(4);
    for (int i = 0; i < 16; i++) {
        calculator.roll(0);
    }
    EXPECT_EQ(24, calculator.totalScore());
}

TEST_F(BowlingCalculatorTest, PerfectGame)
{
    for (int i = 0; i < 12; i++) {
        calculator.roll(10);
    }
    EXPECT_EQ(300, calculator.totalScore());
}

TEST_F(BowlingCalculatorTest, AllSpares)
{
    for (int i = 0; i < 10; i++) {
        calculator.roll(5);
        calculator.roll(5);
    }
    calculator.roll(5);
    EXPECT_EQ(150, calculator.totalScore());
}

TEST_F(BowlingCalculatorTest, CurrentFrame)
{
    calculator.roll(5);
    calculator.roll(5);
    calculator.roll(5);
    EXPECT_EQ(2, calculator.getCurrentFrame());
}

TEST_F(BowlingCalculatorTest, FrameScores)
{
    calculator.roll(10);
    calculator.roll(3);
    calculator.roll(4);
    EXPECT_EQ(17, calculator.getFrameScore(1));
    EXPECT_EQ(7, calculator.getFrameScore(2));
}

TEST_F(BowlingCalculatorTest, RollsInFrame)
{
    calculator.roll(10);
    calculator.roll(7);
    calculator.roll(3);
    EXPECT_EQ(std::vector<int>{10}, calculator.getRollsInFrame(1));
    std::vector<int> testData = std::vector<int>{7, 3};
    std::vector<int> testRolls = calculator.getRollsInFrame(2);
    EXPECT_EQ(testData[0], testRolls[0]);
}

TEST_F(BowlingCalculatorTest, GameOver)
{
    EXPECT_FALSE(calculator.isGameOver());
    for (int i = 0; i < 20; i++) {
        calculator.roll(0);
    }
    EXPECT_TRUE(calculator.isGameOver());
}

TEST_F(BowlingCalculatorTest, ExampleTest)
{
    calculator.roll(10);
    EXPECT_EQ(10, calculator.totalScore());

    calculator.roll(7);
    EXPECT_EQ(24, calculator.totalScore());
    calculator.roll(3);
    EXPECT_EQ(30, calculator.totalScore());

    calculator.roll(7);
    calculator.roll(2);

    calculator.roll(9);
    calculator.roll(1);

    calculator.roll(10);

    calculator.roll(10);

    calculator.roll(10);

    calculator.roll(2);
    calculator.roll(3);

    calculator.roll(6);
    calculator.roll(4);

    calculator.roll(7);
    calculator.roll(3);
    calculator.roll(3);
    EXPECT_EQ(168, calculator.totalScore());
    EXPECT_EQ(20, calculator.getFrameScore(1));
    EXPECT_EQ(17, calculator.getFrameScore(2));
    EXPECT_EQ(9, calculator.getFrameScore(3));
    EXPECT_EQ(20, calculator.getFrameScore(4));
    EXPECT_EQ(30, calculator.getFrameScore(5));
    EXPECT_EQ(22, calculator.getFrameScore(6));
    EXPECT_EQ(15, calculator.getFrameScore(7));
    EXPECT_EQ(5, calculator.getFrameScore(8));
    EXPECT_EQ(17, calculator.getFrameScore(9));
    EXPECT_EQ(13, calculator.getFrameScore(10));
}