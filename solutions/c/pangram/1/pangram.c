#include "pangram.h"
#include <ctype.h>
#include <string.h>

bool is_pangram(const char *sentence) {
   if (sentence == NULL)
      return false;

   int freq[26] = {0};
   int len = strlen(sentence);
   int i, ch;

   for (i = 0; i < len; i++)
      if (isalpha(ch = tolower(sentence[i])))
         freq[ch - 'a']++;

   for (i = 0; i < 26; i++)
      if (freq[i] == 0)
         return false;
   return true;
}
