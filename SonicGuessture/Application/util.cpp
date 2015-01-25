#include "util.h"

#include <algorithm>

int clamp(int val, int min, int max){
    return std::min(max, std::max(min, val));
}
