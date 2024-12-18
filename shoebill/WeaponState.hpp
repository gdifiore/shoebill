/**
 * @class WeaponState
 * @brief Represents the state of a weapon, including movement and aiming.
 */
class WeaponState {
public:
    /**
     * @brief Constructs a WeaponState with default values.
     */
    WeaponState() : moving(false), aiming(false) {}

    /**
     * @brief Sets whether the player is moving.
     * @param movingState True if the player is moving.
     */
    void setMoving(bool movingState) {
        moving = movingState;
    }

    /**
     * @brief Sets whether the player is aiming down sights.
     * @param aimingState True if the player is aiming down sights.
     */
    void setAiming(bool aimingState) {
        aiming = aimingState;
    }

    /**
     * @brief Checks if the player is moving.
     * @return True if the player is moving.
     */
    bool isMoving() const {
        return moving;
    }

    /**
     * @brief Checks if the player is aiming down sights.
     * @return True if the player is aiming.
     */
    bool isAiming() const {
        return aiming;
    }

private:
    bool moving; // True if the player is moving
    bool aiming; // True if the player is aiming down sights (ADS)
};
