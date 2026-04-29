#include "protein_translation.h"
#include <string.h>

#define CODON_SIZE 3
#define CODON_INVALID -1
#define CODON_STOP -2

static int char_to_index(char c) {
   switch (c) {
      case 'A': return 0;
      case 'C': return 1;
      case 'G': return 2;
      case 'U': return 3;
      default: return -1;
   }
}

static int lookup(const char *word) {
   if (word[0] == 'A' && word[1] == 'U' && word[2] == 'G')
      return Methionine;

   if (word[0] == 'U') {
      int a = char_to_index(word[1]);
      int b = char_to_index(word[2]);
      int perfect_hash = (a == -1 || b == -1) ? -1 : (a<<2) + b;
      
      switch (perfect_hash) {
         /* UAA */ case  0: return CODON_STOP;
         /* UAC */ case  1: return Tyrosine;
         /* UAG */ case  2: return CODON_STOP;
         /* UAU */ case  3: return Tyrosine;

         /* UCA */ case  4: return Serine;
         /* UCC */ case  5: return Serine;
         /* UCG */ case  6: return Serine;
         /* UCU */ case  7: return Serine;

         /* UGA */ case  8: return CODON_STOP;
         /* UGC */ case  9: return Cysteine;
         /* UGG */ case 10: return Tryptophan;
         /* UGU */ case 11: return Cysteine;

         /* UUA */ case 12: return Leucine;
         /* UUC */ case 13: return Phenylalanine;
         /* UUG */ case 14: return Leucine;
         /* UUU */ case 15: return Phenylalanine;
      }
   }

   return CODON_INVALID;
}


protein_t protein(const char *rna) {
   protein_t p = { .valid = true, .count = 0 };

   size_t len = strlen(rna);

   int amino;
   for (size_t i = 0; i < len; i += CODON_SIZE) {
      amino = lookup(rna+i);

      if (amino == CODON_INVALID) {
         p.valid = false;
         break;
      }

      if (amino == CODON_STOP) 
         break;

      p.amino_acids[p.count++] = amino;
   }

   return p;
}
