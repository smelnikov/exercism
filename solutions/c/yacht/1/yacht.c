#include "yacht.h"

int score(dice_t dice, category_t category) 
{
   int count[7] = {0};
   int sum = 0;

   for (int i = 0; i < 5; i++) {
      int face = dice.faces[i];
      count[face]++;
      sum += face;
   }

   if (category >= ONES && category <= SIXES) {
      int face = category + 1;
      return face * count[face];
   };

   switch (category) {
   case FULL_HOUSE:
      {
         int pair = 0;
         int triple = 0;
         for (int face = 1; face <= 6; face++) {
            if (count[face] == 2) 
               pair = face;
            if (count[face] == 3) 
               triple = face;
         }
         return pair && triple ? sum : 0;
      }

   case FOUR_OF_A_KIND:
      for (int face = 1; face <= 6; face++)
         if (count[face] >= 4)
            return 4 * face;
      return 0;

   case LITTLE_STRAIGHT:
      return count[1] && count[2] && count[3] && count[4] && count[5] ? 30 : 0;

   case BIG_STRAIGHT:
      return count[2] && count[3] && count[4] && count[5] && count[6] ? 30 : 0;

   case CHOICE:
      return sum;

   case YACHT:
      for (int face = 1; face <= 6; face++)
         if (count[face] == 5)
            return 50;
      return 0;

   default: 
      return 0;
   }
}
