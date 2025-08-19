class BowlingCalculator {
public:
    BowlingCalculator();
    void roll(int pins);
    int totalScore() const;

private:
    int score;
};