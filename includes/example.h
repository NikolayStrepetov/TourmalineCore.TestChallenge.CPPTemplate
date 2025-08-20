class BowlingCalculator {
public:
    BowlingCalculator();
    void roll(int pins);
    int totalScore() const;

private:
    int rolls[21];
    int currentRoll;
};