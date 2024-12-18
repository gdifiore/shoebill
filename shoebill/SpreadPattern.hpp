#include <vector>


/**
 * @class SpreadPattern
 * @brief Defines different bullet spread patterns for a gun.
 */
class SpreadPattern {
public:
    /**
     * @enum PatternType
     * @brief The type of spread pattern.
     */
    enum PatternType { RANDOM, FIXED, GAUSSIAN };


    /**
     * @brief Constructs a SpreadPattern with the specified type.
     * @param type The spread pattern type.
     */
    explicit SpreadPattern(PatternType type) : type(type), currentPatternIndex(0) {}

    /**
     * @brief Retrieves the next offset in the spread pattern.
     * @param spreadRadius The radius of the spread.
     * @return A pair representing the x and y offset.
     */
    std::pair<float, float> getNextOffset(float spreadRadius) const {
        switch (type) {
        case RANDOM:
            return calculateRandomOffset(spreadRadius);
        case GAUSSIAN:
            return calculateGaussianOffset(spreadRadius);
        case FIXED:
            if (!fixedPattern.empty()) {
                auto offset = fixedPattern[currentPatternIndex];
                currentPatternIndex = (currentPatternIndex + 1) % fixedPattern.size();
                return offset;
            }
            return {0, 0};
        default:
            return {0, 0};
        }
    }

private:
    PatternType type;                               // Type of spread pattern
    mutable int currentPatternIndex;               // Index for fixed pattern
    std::vector<std::pair<float, float>> fixedPattern; // Predefined pattern

    /**
     * @brief Calculates a random offset in the spread.
     * @param spreadRadius The spread radius.
     * @return A pair representing the random offset.
     */
    std::pair<float, float> calculateRandomOffset(float spreadRadius) const {
        static std::default_random_engine generator;
        std::uniform_real_distribution<float> angleDist(0, 2 * M_PI);
        std::uniform_real_distribution<float> radiusDist(0, spreadRadius);

        float angle = angleDist(generator);
        float radius = radiusDist(generator);

        return {radius * std::cos(angle), radius * std::sin(angle)};
    }

    /**
     * @brief Calculates an offset using a Gaussian distribution.
     * @param spreadRadius The spread radius.
     * @return A pair representing the Gaussian offset.
     */
    std::pair<float, float> calculateGaussianOffset(float spreadRadius) const {
        static std::default_random_engine generator;
        std::normal_distribution<float> dist(0, spreadRadius / 3.0f);

        return {dist(generator), dist(generator)};
    }
};
