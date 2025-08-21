
#include <iostream>
#include <vector>

#include "example.h"


BowlingCalculator::BowlingCalculator() : currentRoll(0) {
    std::fill_n(rolls, 21, 0);
}

void BowlingCalculator::roll(int pins) {
    rolls[currentRoll++] = pins;
}

int BowlingCalculator::totalScore() const {
    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; frame++) {
        if (rolls[rollIndex] == 10) {
            score += 10 + rolls[rollIndex + 1] + rolls[rollIndex + 2];
            rollIndex++;
        }
        else if (rolls[rollIndex] + rolls[rollIndex + 1] == 10) {
            score += 10 + rolls[rollIndex + 2];
            rollIndex += 2;
        }
        else {
            score += rolls[rollIndex] + rolls[rollIndex + 1];
            rollIndex += 2;
        }
    }


    return score;
}

int BowlingCalculator::getCurrentFrame() const {
    int frame = 0;
    int rollIndex = 0;

    while (rollIndex < currentRoll && frame < 10) {
        if (rolls[rollIndex] == 10) {
            rollIndex ++;
        }
        else {
            rollIndex += 2;
        }
        frame ++;
    }

    return frame;
}

int BowlingCalculator::getFrameScore(int frame) const {
    if (frame < 1 || frame > 10) {
        throw std::invalid_argument("Frame must be between 1 and 10");
    }

    int frameIndex = 0;
    int rollIndex = 0;
    int frameScore = 0;

    while (frameIndex < frame -1) {
        if (isStrike(rollIndex)) {
            rollIndex ++;
        }
        else {
            rollIndex += 2;
        }
        frameIndex ++;
    }
    
    if (isStrike(rollIndex)) {
        frameScore = 10 + strikeBonus(rollIndex);
    }
    else if (isSpare(rollIndex)) {
        frameScore = 10 + spareBonus(rollIndex);
    }
    else {
        frameScore = rolls[rollIndex] + rolls[rollIndex + 1];
    }

    return frameScore;
}

std::vector<int> BowlingCalculator::getRollsInFrame(int frame) const {
    if (frame < 1 || frame > 10) {
        throw std::invalid_argument("Frame must be between 1 and 10");
    }

    int frameIndex = 0;
    int rollIndex = 0;
    int frameScore = 0;
    std::vector<int> frameRolls;

    while (frameIndex < frame -1) {
        if (isStrike(rollIndex)) {
            rollIndex ++;
        }
        else {
            rollIndex += 2;
        }
        frameIndex ++;
    }

    if (isStrike(rollIndex)) {
        frameRolls.push_back(rolls[rollIndex]);    
    }
    else {
        frameRolls.push_back(rolls[rollIndex]);
        frameRolls.push_back(rolls[rollIndex + 1]);
    }

    return frameRolls;
}

bool BowlingCalculator::isStrike(int rollIndex) const {
    return rollIndex < currentRoll && rolls[rollIndex] == 10;
}

bool BowlingCalculator::isSpare(int rollIndex) const {
    return rollIndex + 1 < currentRoll &&
           rolls[rollIndex] + rolls[rollIndex + 1] == 10;
}

int BowlingCalculator::strikeBonus(int rollIndex) const {
    if (rollIndex + 2 < currentRoll) {
        return rolls[rollIndex + 1] + rolls[rollIndex + 2];
    }
    else if (rollIndex + 1 < currentRoll) {
        return rolls[rollIndex + 1];
    }

    return 0;
}

int BowlingCalculator::spareBonus(int rollIndex) const {
    if (rollIndex + 2 < currentRoll) {
        return rolls[rollIndex + 2];
    }

    return 0;
}