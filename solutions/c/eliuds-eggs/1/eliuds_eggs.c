#include "eliuds_eggs.h"


int egg_count(int code) {
    int count = 0;
    while (code) {
        count += code&1;
        code >>= 1;
    }
    return count;
}
