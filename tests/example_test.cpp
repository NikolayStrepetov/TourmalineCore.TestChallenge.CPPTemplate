
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