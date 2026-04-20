#include "luhn.h"
#include <ctype.h>
#include <string.h>

bool luhn(const char *num) {
   int sum = 0, digits = 0;

   for (int i = strlen(num) - 1; i >= 0; i--) {
      if (num[i] == ' ')
         continue;
      if (!isdigit(num[i]))
         return false;

      int curr = num[i] - '0';

      if (++digits % 2 == 0) {
         curr *= 2;
         if (curr > 9)
            curr -= 9;
      }

      sum += curr;
   }
   return digits > 1 && sum % 10 == 0;
}
