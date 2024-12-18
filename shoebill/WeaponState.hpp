class WeaponState {
public:
    WeaponState();

    void setMoving(bool moving);
    void setAiming(bool aiming);
    bool isMoving() const;
    bool isAiming() const;

private:
    bool moving; // is player moving
    bool aiming; // is player ADSing
};
