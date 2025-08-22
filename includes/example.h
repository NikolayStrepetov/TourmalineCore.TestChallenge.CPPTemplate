#include <vector>

class BowlingCalculator {
public:
    BowlingCalculator();
    void roll(int pins);
    int totalScore() const;
    int getCurrentFrame() const;
    int getFrameScore(int frame) const;
    std::vector<int> getRollsInFrame(int frame) const;
    bool isGameOver() const;

private:
    int rolls[21];
    int currentRoll;

    bool isStrike(int rollIndex) const;
    bool isSpare(int rollIndex) const;
    int strikeBonus(int rollIndex) const;
    int spareBonus(int rollIndex) const;
};