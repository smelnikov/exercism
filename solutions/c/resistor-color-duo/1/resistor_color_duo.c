#include "resistor_color_duo.h"

#define COUNT_MAX 2

uint16_t color_code(resistor_band_t bands[]) {
   uint16_t result = 0;
   for (uint8_t i = 0; i < COUNT_MAX; i++) {
      result *= 10;
      result += bands[i];
   }
   return result;
}
