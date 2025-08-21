class BowlingCalculator {
public:
    BowlingCalculator();
    void roll(int pins);
    int totalScore() const;
    int getCurrentFrame() const;
    int getFrameScore(int frame) const;

private:
    int rolls[21];
    int currentRoll;

    bool isStrike(int frameIndex) const;
    bool isSpare(int frameIndex) const;
    int strikeBonus(int frameIndex) const;
    int spareBonus(int frameIndex) const;
};