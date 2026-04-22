#include "rotational_cipher.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char *rotate(const char *text, int shift_key) {
    int len = strlen(text);
    char *buf = malloc((len + 1) + len);
    buf[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (!isalpha(text[i]))
            buf[i] = text[i];
        else if (isupper(text[i]))
            buf[i] = (text[i] - 'A' + shift_key) % 26 + 'A';
        else
            buf[i] = (text[i] - 'a' + shift_key) % 26 + 'a';
    }

    return buf;
}
