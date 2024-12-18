#include <iostream>

#include "shoebill/Gun.hpp"
#include "shoebill/Recoil.hpp"
#include "shoebill/SpreadPattern.hpp"
#include "shoebill/WeaponState.hpp"

int main() {
    Gun ak47("AK-47", 1.0f, 5.0f, 0.2f, 0.1f);
    Recoil recoil(3.0f, 0.1f);
    SpreadPattern pattern(SpreadPattern::RANDOM);
    WeaponState state;

    state.setMoving(true);
    state.setAiming(false);

    for (int i = 0; i < 10; ++i) {
        auto [spreadX, spreadY] = ak47.fire(state.isMoving(), state.isAiming());
        auto [recoilX, recoilY] = recoil.getRecoilOffset();

        std::cout << "Shot " << i + 1 << " Offset: (" << spreadX + recoilX << ", " << spreadY + recoilY << ")\n";

        recoil.applyRecoil();
        recoil.recoverRecoil();
    }

    return 0;
}
