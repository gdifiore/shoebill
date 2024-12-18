class SpreadPattern {
public:
    enum PatternType { RANDOM, FIXED, GAUSSIAN };

    SpreadPattern(PatternType type);

    // pattern calculation
    std::pair<float, float> getNextOffset(float spreadRadius) const;

private:
    PatternType type; // curr pattern type
    std::vector<std::pair<float, float>> fixedPattern; // fixed spread patterns
    mutable int currentPatternIndex; // current index in fixed pattern

    std::pair<float, float> calculateRandomOffset(float spreadRadius) const;
    std::pair<float, float> calculateGaussianOffset(float spreadRadius) const;
};
