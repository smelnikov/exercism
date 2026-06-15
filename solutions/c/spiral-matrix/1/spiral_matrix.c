#include "spiral_matrix.h"
#include <stdlib.h>

spiral_matrix_t *spiral_matrix_create(int size)
{
   spiral_matrix_t *s = malloc(sizeof(spiral_matrix_t));
   if (s == NULL)
      return NULL;

   if (size <= 0) {
      s->size = 0;
      return s;
   }

   s->size = size;

   s->matrix = malloc(size * sizeof(*s->matrix));
   if (s->matrix == NULL) {
      free(s);
      return NULL;
   }

   for (int i = 0; i < size; i++) {
      s->matrix[i] = malloc(size * sizeof(*s->matrix[i]));
      if (s->matrix[i] == NULL) {
         while (i--)
            free(s->matrix[i]);
         free(s->matrix);
         free(s);
         return NULL;
      }
   }

   int top = 0, bottom = size - 1; 
   int left = 0, right = size - 1;
   int value = 1;

   while (top <= bottom && left <= right) {
      for (int col = left; col <= right; col++)
         s->matrix[top][col] = value++;
      top++;

      for (int row = top; row <= bottom; row++)
         s->matrix[row][right] = value++;
      right--;

      for (int col = right; col >= left; col--)
         s->matrix[bottom][col] = value++;
      bottom--;

      for (int row = bottom; row >= top; row--)
         s->matrix[row][left] = value++;
      left++;
   }

   return s;
}

void spiral_matrix_destroy(spiral_matrix_t *s)
{
   if (s == NULL)
      return;

   for (int i = 0; i < s->size; i++)
      free(s->matrix[i]);

   free(s->matrix);
   free(s);
}
