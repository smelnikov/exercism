#include "binary_search.h"

const int *binary_search(int value, const int *arr, size_t length) {
   int lo = 0;
   int hi = length - 1;
   int mid;
   while (lo <= hi) {
      mid = (hi + lo) / 2;
      if (arr[mid] == value) {
         return arr + mid;
      } else if (arr[mid] < value) {
         lo = mid + 1;
      } else {
         hi = mid - 1;
      }
   }
   return NULL;
}
