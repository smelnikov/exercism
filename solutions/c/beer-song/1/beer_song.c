#include "beer_song.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
    uint8_t end_bottles = start_bottles - take_down + 1;

    for (int i = start_bottles; i >= end_bottles; i--) {
        char *line1 = malloc(64 * sizeof(char));
        char *line2 = malloc(80 * sizeof(char));

        if (i == 0) {
            snprintf(
                    line1, 64, 
                    "No more bottles of beer on the wall, no more bottles of beer."
                    );
            snprintf(
                    line2, 80,
                    "Go to the store and buy some more, 99 bottles of beer on the wall."
                    );
        } else {
            snprintf(
                    line1, 64, 
                    "%d bottle%s of beer on the wall, %d bottle%s of beer.", 
                    i, i == 1 ? "" : "s", 
                    i, i == 1 ? "" : "s"
                    );

            if (i == 1) 
                snprintf(
                        line2, 80,
                        "Take it down and pass it around, no more bottles of beer on the wall."
                        );
            else
                snprintf(
                        line2, 80, 
                        "Take one down and pass it around, %d bottle%s of beer on the wall.", 
                        i - 1,
                        i == 2 ? "" : "s"
                        );
        }

        *(song++) = line1;
        *(song++) = line2;

        if (i != end_bottles)
            *(song++) = calloc(1, sizeof(char));
    }
}
