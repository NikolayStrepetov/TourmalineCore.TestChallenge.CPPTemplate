
#include <iostream>

#include "example.h"


BowlingCalculator::BowlingCalculator() : score(0) {}

void BowlingCalculator::roll(int pins) {
    score += pins;
}

int BowlingCalculator::totalScore() const {
    return score;
}