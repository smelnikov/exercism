#include "roman_numerals.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
   uint16_t value;
   char     *text;
} pair_t;

static pair_t map[] = {
   {1000,   "M"},
   {900,    "CM"},
   {500,    "D"},
   {400,    "CD"},
   {100,    "C"},
   {90,     "XC"},
   {50,     "L"},
   {40,     "XL"},
   {10,     "X"},
   {9,      "IX"},
   {5,      "V"},
   {4,      "IV"},
   {1,      "I"},
};
static char length = sizeof(map) / sizeof(pair_t);

char *to_roman_numeral(unsigned int number)
{
   char *string = malloc(16);
   char len = 0;

   for (int i = 0; i < length; i++) {
      pair_t pair = map[i];
      while (pair.value <= number) {
         len += sprintf(string + len, "%s", pair.text);
         number -= pair.value;
      }
   }

   return string;
}
