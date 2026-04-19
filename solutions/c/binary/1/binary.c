#include "binary.h"
#include "string.h"


int convert(const char *input) {
   int value = 0;
   while (*input) {
      value <<= 1;
      switch (*input) {
         case '0':
            break;
         case '1':
            value |= 1;
            break;
         default:
            return INVALID;
      }
      input++;
   }
   return value;
}
