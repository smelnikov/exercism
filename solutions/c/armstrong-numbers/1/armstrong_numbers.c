#include "armstrong_numbers.h"
#include <math.h>

bool is_armstrong_number(int candidate) {
   int digits[8];
   int count = 0;
   int number = candidate;
   while (number) {
      digits[count++] = number % 10;
      number /= 10;
   }
   for (int i = 0; i < count; i++)
      number += pow(digits[i], count);
   return number == candidate;
}
