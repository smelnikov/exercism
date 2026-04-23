#include "reverse_string.h"
#include <string.h>
#include <stdlib.h>

char *reverse(const char *value) {
   int len = strlen(value);

   char *result = malloc((len + 1) * sizeof(char));

   for (int l = 0, r = len - 1; r >= 0; r--)
      result[l++] = value[r];
   result[len] = '\0';

   return result;

}
