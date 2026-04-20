#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t bands[]) {
   resistor_value_t result = {
      .value = bands[0], 
      .unit = OHMS
   };
   uint8_t zeroes = bands[2];

   if (bands[1] == BLACK)
      zeroes++;
   else
      result.value = result.value * 10 + bands[1];

   if (zeroes >= GIGAOHMS) {
      result.unit = GIGAOHMS;
   } else if (zeroes >= MEGAOHMS) {
      result.unit = MEGAOHMS;
   } else if (zeroes >= KILOOHMS) {
      result.unit = KILOOHMS;
   }
   zeroes -= result.unit;

   while (zeroes--)
      result.value *= 10;

   return result;
}
