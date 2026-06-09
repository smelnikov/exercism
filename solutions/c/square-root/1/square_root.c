#include "square_root.h"

uint16_t 
square_root(uint32_t target)
{
   uint32_t lo = 0, hi = target + 1;

   while (lo != hi - 1) {
      uint32_t mid = (lo + hi)>>1;
      if (mid * mid <= target)
         lo = mid;
      else
         hi = mid;
   }
   return lo;
}
