/**
 * @class Recoil
 * @brief Manages recoil behavior for a gun, including vertical and horizontal offsets.
 */
class Recoil {
public:
    /**
     * @brief Constructs a Recoil object with specified properties.
     * @param maxRecoilAngle The maximum vertical recoil angle.
     * @param recoveryRate The rate at which recoil recovers.
     */
    Recoil(float maxRecoilAngle, float recoveryRate)
        : maxRecoilAngle(maxRecoilAngle), currentRecoilAngle(0), recoveryRate(recoveryRate),
          horizontalRecoilAngle(0) {}

    /**
     * @brief Applies recoil after a shot.
     */
    void applyRecoil() {
        static std::default_random_engine generator;
        std::uniform_real_distribution<float> horizontalDist(-maxRecoilAngle / 2, maxRecoilAngle / 2);

        currentRecoilAngle = std::min(maxRecoilAngle, currentRecoilAngle + recoveryRate);
        horizontalRecoilAngle = horizontalDist(generator);
    }

    /**
     * @brief Gradually reduces recoil over time.
     */
    void recoverRecoil() {
        currentRecoilAngle = std::max(0.0f, currentRecoilAngle - recoveryRate);
        horizontalRecoilAngle *= 0.9f; // Gradual decay for horizontal recoil
    }

    /**
     * @brief Retrieves the current recoil offset.
     * @return A pair representing the horizontal and vertical recoil offsets.
     */
    std::pair<float, float> getRecoilOffset() const {
        return {horizontalRecoilAngle, currentRecoilAngle};
    }

private:
    float maxRecoilAngle;        // Maximum vertical recoil angle
    float currentRecoilAngle;    // Current vertical recoil angle
    float recoveryRate;          // Rate of recoil recovery
    float horizontalRecoilAngle; // Current horizontal recoil offset
};
