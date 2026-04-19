#include "resistor_color.h"
#include <stdint.h>


uint16_t color_code(resistor_band_t color) {
   return color;
}

resistor_band_t colors_array[] = {
   BLACK,
   BROWN,
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   BLUE,
   VIOLET,
   GREY,
   WHITE,
};

resistor_band_t *colors(void) {
   return colors_array;
}
