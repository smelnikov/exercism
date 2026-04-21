#include "sum_of_multiples.h"

unsigned int sum(const unsigned int *factors, const size_t number_of_factors,
                 const unsigned int limit) {
    unsigned int result = 0;
    for (unsigned int num = 1; num < limit; num++)
        for (size_t i = 0; i < number_of_factors; i++)
            if (factors[i] && num % factors[i] == 0) {
                result += num;
                break; // only a single unique occurence is included
            }
    return result;
}
