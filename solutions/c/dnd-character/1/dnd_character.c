#include "dnd_character.h"
#include <math.h>
#include <stdlib.h>

int ability(void) {
   int dice[7] = {0};
   int rolls = 4;
   while (rolls) {
      dice[1 + rand() % 6]++;
      rolls--;
   }
   rolls = 3;
   int value = 0;
   for (int i = 6; i >= 1 && rolls; i--) {
      while (dice[i]--) {
         value += i;
         rolls--;
      }
   }
   return value;
}

int modifier(int score) {
   return floorf((float)(score - 10) / 2);
}

dnd_character_t make_dnd_character(void) {
   dnd_character_t stats = {
      .strength=ability(),
      .dexterity=ability(),
      .constitution=ability(),
      .intelligence=ability(),
      .wisdom=ability(),
      .charisma=ability(),
      .hitpoints=10,
   };
   stats.hitpoints += modifier(stats.constitution);
   return stats;
}
