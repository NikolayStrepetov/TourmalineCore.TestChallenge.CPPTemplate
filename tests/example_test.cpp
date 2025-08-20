
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