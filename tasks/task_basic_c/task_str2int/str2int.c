#include <assert.h>
#include "str2int.h"
#include "stdio.h"

int str2int(const char *str) {
    int z = 1;
    int r = 0;

    if (*str =='-'){
        z = -1;
        str++;
    }
    else if (*str =='+'){
        str++;
    }
    int c = 0;
    while (*str != '\0'){
        r = r * 10 + (*str - '0');
        c += 1;
        str++;
        assert(z == -1 && r == -2147483648 || z == -1 && r >= 0 && c <= 9 || z ==1 && r >= 0);
    }
    assert(c > 0);
    return r * z;
}