#include "raindrops.h"
#include <stdio.h>
#include <string.h>

void convert(char result[], int drops) {
   int is_div = 0;
   if (drops % 3 == 0) {
      strcat(result, "Pling");
      is_div = 1;
   }
   if (drops % 5 == 0) {
      strcat(result, "Plang");
      is_div = 1;
   }
   if (drops % 7 == 0) {
      strcat(result, "Plong");
      is_div = 1;
   }
   if (is_div == 0)
      sprintf(result, "%d", drops);
}
