#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "allpos.h"

int main() {
    FILE *file;
    file = fopen("access_logmini", "r");
    char str[500];
    int ans1 = 0;
    allpos pos = init();
    int i = 0;
    while (!feof(file)) {
        fgets(str, 500, file);

        //1 вопрос
        pos = split(str);
        char status = str[pos.statuss];
        if (status == '5')
            ans1++;
    }

    // продолжение второго вопроса
    printf("%d", ans1);
    // ответ 76
    fclose(file);
    return 0;
}