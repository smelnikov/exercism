#include "perfect_numbers.h"

kind classify_number(int num) {
   if (num < 1)
      return ERROR;

   int aliquot_sum = 0;

   for (int i = 1; i <= num / 2; i++) {
      if (num % i == 0)
         aliquot_sum += i;
   }

   if (num < aliquot_sum)
      return ABUNDANT_NUMBER;
   if (num > aliquot_sum)
      return DEFICIENT_NUMBER;
   return PERFECT_NUMBER;
}
