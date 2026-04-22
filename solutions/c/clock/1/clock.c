#include "clock.h"
#include <stdio.h>
#include <string.h>

#define HOUR_MAX 24
#define MINUTE_MAX 60 

#define maxmod(value, max) ((max + ((value) % max)) % max)

#define floordiv(numerator, denominator)                                       \
   ((numerator) < 0 ? (numerator + 1) / denominator - 1                        \
                    : numerator / denominator)                                 

void clock_mod(int *hour, int *minute) {
   *hour = maxmod(*hour + floordiv(*minute, MINUTE_MAX), HOUR_MAX);
   *minute = maxmod(*minute, MINUTE_MAX);
}

clock_t clock_create(int hour, int minute) {
   clock_t clock;
   clock_mod(&hour, &minute);
   sprintf(clock.text, "%.2d:%.2d", hour, minute);
   return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
   int hour, minute;
   sscanf(clock.text, "%2d:%2d", &hour, &minute);
   minute += minute_add;
   return clock_create(hour, minute);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
   int hour, minute;
   sscanf(clock.text, "%2d:%2d", &hour, &minute);
   minute -= minute_subtract;
   return clock_create(hour, minute);
}

bool clock_is_equal(clock_t a, clock_t b) {
   return strcmp(a.text, b.text) == 0;
}
