#include "gigasecond.h"

#define GIGASECOND 1000000000

void gigasecond(time_t input, char *output, size_t size) {
   input += GIGASECOND;
   strftime(output, size, "%F %T", gmtime(&input));
}
