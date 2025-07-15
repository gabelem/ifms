#include <stdlib.h>
#include <string.h>

char* inverterString(const char* str) {
    int len = strlen(str);
    char* invertida = (char*) malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++)
        invertida[i] = str[len - 1 - i];
    invertida[len] = '\0';
    return invertida;
}

