#ifndef NUCLEOTIDE_COUNT_H
#define NUCLEOTIDE_COUNT_H

/*         4   nucleotides
*  10*4 char   uint32 representation
*   2*4 char   name and separator
*   4-1 char   spaces
*     1 char   string terminator
*/
#define BUFSIZE 64

char *count(const char *dna_strand);

#endif
