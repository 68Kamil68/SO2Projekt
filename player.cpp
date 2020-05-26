#include "player.h"
#include <tuple>

std::tuple<int, int> Player:: GetCoords() {
    return std::make_tuple(CurrX, CurrY);
}