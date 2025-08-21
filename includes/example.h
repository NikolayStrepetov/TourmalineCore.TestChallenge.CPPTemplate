class BowlingCalculator {
public:
    BowlingCalculator();
    void roll(int pins);
    int totalScore() const;
    int getCurrentFrame() const;
    int getFrameScore() const;

private:
    int rolls[21];
    int currentRoll;
};