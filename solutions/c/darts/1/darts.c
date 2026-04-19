#include "darts.h"

uint8_t score(coordinate_t coord) {
   float dist = coord.x * coord.x + coord.y * coord.y;
   if (dist > 100)
      return 0;
   if (dist > 25)
      return 1;
   if (dist > 1)
      return 5;
   return 10;
}
