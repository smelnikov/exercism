#include "protein_translation.h"
#include <string.h>

#define CODON_SIZE 3
#define CODON_INVALID -1
#define CODON_STOP -2

int char_to_index(char c) {
   switch (c) {
      case 'A': return 0;
      case 'C': return 1;
      case 'G': return 2;
      case 'U': return 3;
      default: return -1;
   }
}

// perfect hash
int hash(char a, char b) {
   int index_a = char_to_index(a);
   int index_b = char_to_index(b);
   if (index_a == -1 || index_b == -1) 
      return -1;

   return (index_a<<2) + index_b;

}

int lookup(const char *word) {
   if (word[0] == 'A' && word[1] == 'U' && word[2] == 'G')
      return Methionine;

   if (word[0] == 'U')
      switch (hash(word[1], word[2])) {
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
                   default: return CODON_INVALID;
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
