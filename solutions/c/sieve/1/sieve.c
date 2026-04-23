#include "sieve.h"
#include <stdbool.h>
#include <string.h>

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
   bool s[++limit];
   memset(s, 1, sizeof(s));

   size_t count = 0;

   for (uint32_t i = 2; i < limit && count < max_primes; i++) {
      if (s[i] == 0)
         continue;
      for (uint32_t j = i; j < limit; j += i)
         s[j] = 0;
      primes[count++] = i;
   }

   return count;
}
