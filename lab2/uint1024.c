#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>

int max(int a, int b){
    if (a > b)
        return a;
     return b;
}

typedef struct uint1024_t{
    char *n;
    int index;
} uint1024_t;

uint1024_t init(){
    uint1024_t num;
    num.index = 0;
    num.n = (char *) malloc(129 * sizeof(char));
    memset(num.n, 0, 129);
    return num;
}

void printf_value(uint1024_t x){
    char10 result = init10();
    char10 degree = init10();
    degree.n[0] = 1;
    for(int i = 0; i <= x.index; ++i){
        int cur = (x.n[i / 8] >> (7 - i % 8)) & 1;
        if (cur){
            result = add10(result, degree);
        }
        degree = add10(degree, degree);
    }
    printf10(result);
    free_char10(result);
    free_char10(degree);
}

void fprintf_value(uint1024_t x, FILE *file){
    char10 result = init10();
    char10 degree = init10();
    degree.n[0] = 1;
    for(int i = 0; i <= x.index; ++i){
        int cur = (x.n[i / 8] >> (7 - i % 8)) & 1;
        if (cur){
            result = add10(result, degree);
        }
        degree = add10(degree, degree);
    }
    fprintf10(result, file);
    free_char10(result);
    free_char10(degree);
}

int main(void) {
    uint1024_t a = init();
    uint1024_t b = init();
    uint1024_t sum = init();
    uint1024_t sub = init();
    uint1024_t mult = init();
}