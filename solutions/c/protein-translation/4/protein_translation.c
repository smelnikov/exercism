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

int u_lookup[16] = {
   /* UAA */ CODON_STOP,
   /* UAC */ Tyrosine,
   /* UAG */ CODON_STOP,
   /* UAU */ Tyrosine,

   /* UCA */ Serine,
   /* UCC */ Serine,
   /* UCG */ Serine,
   /* UCU */ Serine,

   /* UGA */ CODON_STOP,
   /* UGC */ Cysteine,
   /* UGG */ Tryptophan,
   /* UGU */ Cysteine,

   /* UUA */ Leucine,
   /* UUC */ Phenylalanine,
   /* UUG */ Leucine,
   /* UUU */ Phenylalanine,
};

static int lookup(const char *word) {
   if (word[0] == 'A' && word[1] == 'U' && word[2] == 'G')
      return Methionine;

   if (word[0] == 'U') {
      int a = char_to_index(word[1]);
      int b = char_to_index(word[2]);

      if (a == -1 || b == -1)
         return CODON_INVALID;
         
      int perfect_hash = (a<<2) + b;
      
      return u_lookup[perfect_hash];
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
