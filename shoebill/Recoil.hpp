class Recoil {
public:
    Recoil(float maxRecoilAngle, float recoveryRate);

    void applyRecoil(); // add recoil after a shot
    void recoverRecoil(); // reduce recoil over time
    std::pair<float, float> getRecoilOffset() const; // current recoil offset

private:
    float maxRecoilAngle;   // max vertical recoil angle
    float currentRecoilAngle; // curr vertical recoil angle
    float recoveryRate;     // rate at which recoil resets
    float horizontalRecoilAngle; // horiz recoil component

    float calculateRecoilAngle() const; // random recoil deviations
};
