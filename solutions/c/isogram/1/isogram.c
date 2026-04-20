#include "isogram.h"
#include <ctype.h>
#include <string.h>

bool is_isogram(const char phrase[]) {
   if (phrase == NULL)
      return NULL;

   char freq[26] = {0};

   for (int curr, i = 0; phrase[i]; i++) {
      curr = tolower(phrase[i]);
      if (isalpha(curr) && (++freq[curr - 'a']) > 1)
         return false;
   }

   return true;
}
