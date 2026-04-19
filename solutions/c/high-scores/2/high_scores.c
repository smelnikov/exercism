#include "high_scores.h"

int32_t latest(const int32_t *scores, size_t scores_len) {
    return scores[scores_len - 1];
}

int32_t personal_best(const int32_t *scores, size_t scores_len) {
    int best = 0;
    for (size_t i = 0; i < scores_len; i++)
        if (scores[i] > best)
            best = scores[i];
    return best;
}

size_t personal_top_three(const int32_t *scores, size_t scores_len,
        int32_t *output) {
    int32_t first, second, third;
    first = second = third = INT32_MIN;

    size_t i;
    for (i = 0; i < scores_len; i++) {
        if (scores[i] > first) {
            third = second;
            second = first;
            first = scores[i];
        } else if (scores[i] > second) {
            third = second;
            second = scores[i];
        } else if (scores[i] > third) {
            third = scores[i];
        }
    }

    i = 0;
    if (first != INT32_MIN)
        output[i++] = first;
    if (second != INT32_MIN)
        output[i++] = second;
    if (third != INT32_MIN)
        output[i++] = third;

    return i;
}
