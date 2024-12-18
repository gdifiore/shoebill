class Gun {
public:
    Gun(std::string name, float baseSpread, float maxSpread, float recoilIncrement, float recoilDecrement);

    // Fire-related methods
    std::pair<float, float> fire(bool isMoving, bool isADS); // Returns adjusted aim offset
    void reload(); // Resets inaccuracy and other state for a new magazine

    // Accessors
    std::string getName() const;
    float getCurrentSpread() const;

private:
    // Attributes
    std::string name;
    float baseSpread;      // Minimum spread
    float maxSpread;       // Maximum spread
    float currentSpread;   // Current spread (dynamic)
    float recoilIncrement; // Amount spread increases per shot
    float recoilDecrement; // Amount spread decreases during cooldown

    // Helper functions
    std::pair<float, float> calculateSpreadOffset(float spread) const;
};
