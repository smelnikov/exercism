#include "beer_song.h"
#include <stdio.h>

#define BUFSIZE (1024)

static const char *line1[] = {
    "No more bottles of beer on the wall, no more bottles of beer.",
    "1 bottle of beer on the wall, 1 bottle of beer.",
    "%u bottles of beer on the wall, %u bottles of beer."
};

static const char *line2[] = {
    "Go to the store and buy some more, 99 bottles of beer on the wall.",
    "Take it down and pass it around, no more bottles of beer on the wall.",
    "Take one down and pass it around, 1 bottle of beer on the wall.", 
    "Take one down and pass it around, %u bottles of beer on the wall."
};



void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    uint8_t end_bottles = start_bottles - take_down + 1;

    for (int8_t i = start_bottles; i >= end_bottles; i--) {
        snprintf(*song++, BUFSIZE, line1[i > 1 ? 2 : i], i, i);
        snprintf(*song++, BUFSIZE, line2[i - 1 > 1 ? 3 : i], i - 1);
        song++;
    }
}
