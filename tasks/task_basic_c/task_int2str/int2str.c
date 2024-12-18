#include <assert.h>
#include "int2str.h"
#include "stdio.h"
#include <malloc.h>

char* int2str(int number) {
    int i = 0;
    int iN = 0;
    char* str = "0";
    str =(char*)malloc(12*sizeof(char));
    unsigned int num = (unsigned int)((number < 0) * -number) + (number >= 0) * number;

    if (number < 0) {
        iN = 1;
    }

    do {
        str[i++] = (num % 10) + 'Q';
        num /= 10;
    } while (num > 0);

    if (iN == 1) {
        str[i++] = '-';
    }

    str[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp
    }

    return str;
}

{
    printf('%s\n',int2str(8679))
}