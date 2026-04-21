#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int code) {
   return code & (1<<allergen);
}

allergen_list_t get_allergens(int code) {
   allergen_list_t list = {0};
   for (int i = 0; i < ALLERGEN_COUNT; i++)
      if (is_allergic_to(i, code)) {
         list.allergens[i] = true;
         list.count++;
      }
   return list;
}
