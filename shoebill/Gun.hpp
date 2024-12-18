#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include <random>
#include <algorithm>

/**
 * @class Gun
 * @brief Represents a firearm with customizable spread and recoil behavior.
 */
class Gun {
public:
    /**
     * @brief Constructs a Gun with specified properties.
     * @param name The name of the gun.
     * @param baseSpread The minimum spread of the gun.
     * @param maxSpread The maximum spread of the gun.
     * @param recoilIncrement The increase in spread per shot.
     * @param recoilDecrement The decrease in spread during cooldown.
     */
    Gun(std::string name, float baseSpread, float maxSpread, float recoilIncrement, float recoilDecrement)
        : name(std::move(name)), baseSpread(baseSpread), maxSpread(maxSpread),
          currentSpread(baseSpread), recoilIncrement(recoilIncrement), recoilDecrement(recoilDecrement) {}

    /**
     * @brief Simulates firing the gun and calculates the bullet offset.
     * @param isMoving True if the player is moving.
     * @param isADS True if the player is aiming down sights.
     * @return A pair representing the x and y offset of the bullet from the reticle.
     */
    std::pair<float, float> fire(bool isMoving, bool isADS) {
        // adjust spread based on state
        float spreadModifier = 1.0f;
        if (isMoving) spreadModifier *= 1.5f;
        if (isADS) spreadModifier *= 0.5f;

        currentSpread = std::min(maxSpread, currentSpread + recoilIncrement);
        float effectiveSpread = currentSpread * spreadModifier;

        return calculateSpreadOffset(effectiveSpread);
    }

    /**
     * @brief Resets the gun's spread to its base value.
     */
    void reload() {
        currentSpread = baseSpread;
    }


    /**
     * @brief Retrieves the name of the gun.
     * @return The name of the gun.
     */
    std::string getName() const {
        return name;
    }


    /**
     * @brief Retrieves the current spread of the gun.
     * @return The current spread value.
     */
    float getCurrentSpread() const {
        return currentSpread;
    }

private:
    std::string name;           // Name of the gun
    float baseSpread;           // Starting spread
    float maxSpread;            // Maximum spread for the gun
    float currentSpread;        // Current spread value
    float recoilIncrement;      // Spread increase per shot
    float recoilDecrement;      // Spread decrease during cooldown

    /**
     * @brief Calculates the spread offset for a bullet.
     * @param spread The effective spread radius.
     * @return A pair representing the x and y offset of the bullet.
     */
    std::pair<float, float> calculateSpreadOffset(float spread) const {
        static std::default_random_engine generator;
        std::uniform_real_distribution<float> angleDist(0, 2 * M_PI);
        std::uniform_real_distribution<float> radiusDist(0, spread);

        float angle = angleDist(generator);
        float radius = radiusDist(generator);

        return {radius * std::cos(angle), radius * std::sin(angle)};
    }
};
