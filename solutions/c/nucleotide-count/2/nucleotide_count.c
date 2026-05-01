#include "nucleotide_count.h"
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>


char *count(const char *dna_strand) {
    uint32_t a, c, g, t;
    a = c = g = t = 0;

    char *result = calloc(BUFSIZE, sizeof(char));

    for (int i = 0; dna_strand[i] != '\0'; i++)
        switch (dna_strand[i]) {
            case 'A': a++; break;
            case 'C': c++; break;
            case 'G': g++; break;
            case 'T': t++; break;
            default: 
                  return result;
        }

    snprintf(
        result, BUFSIZE, 
        "A:%" PRIu32 " C:%" PRIu32 " G:%" PRIu32 " T:%" PRIu32, 
        a, c, g, t
    );

    return result;
}
