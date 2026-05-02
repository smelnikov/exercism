#include "prime_factors.h"

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
   size_t size = 0;

   for (int prime = 2; n > 1; prime++)
      for (; n % prime == 0; n/=prime)
         factors[size++] = prime;

   return size;
}
