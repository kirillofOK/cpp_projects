#include "header.hpp"

double macheps(void) {
    double e = 1.0;

    while (1.0 + e / 2.0 > 1.0) {
        e /= 2.0;
    }

    return e;
}

