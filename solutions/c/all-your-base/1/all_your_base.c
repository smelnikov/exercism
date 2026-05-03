#include "all_your_base.h"
#include <stddef.h>

#define INVALID 0

size_t rebase(int8_t digits[], int16_t input_base, int16_t output_base, size_t input_length) {
   if (input_base < 2 || output_base < 2 || input_length == 0)
      return INVALID;

   int32_t number = 0;

   for (size_t i = 0; i < input_length; i++) {
      if (digits[i] < 0 || digits[i] >= input_base)
         return INVALID;

      number = number * input_base + digits[i];
   }

   size_t length = 0;

   do {
      digits[length++] = number % output_base;
      number /= output_base;
   } while (number);

   for (size_t i = 0; i < length / 2; i++) {
      int8_t temp = digits[i];
      digits[i] = digits[length - 1 - i];
      digits[length - 1 - i] = temp;
   }
   
   return length;
}
