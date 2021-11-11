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

void free_uint(uint1024_t x){
    free(x.n);
}

void scanf_value(uint1024_t* x){
    char *s = (char *) malloc(310 * sizeof(char));
    scanf("%s", s);
    uint1024_t result = init();
    uint1024_t digit = from_uint(10);
    for (int i = 0; i <= (int) strlen(s) - 1; ++i){
        result = mult_op(result, digit);
        uint1024_t cur_digit = from_uint((unsigned int) (s[i] - '0'));
        result = add_op(result, cur_digit);
    }

    *x = result;
    free(s);
}

void fscanf_value(uint1024_t* x, FILE *file){
    char *s = (char *) malloc(310 * sizeof(char));
    fscanf(file, "%s", s);
    uint1024_t result = init();
    uint1024_t digit = from_uint(10);
    for (int i = 0; i <= (int) strlen(s) - 1; ++i){
        result = mult_op(result, digit);
        uint1024_t cur_digit = from_uint((unsigned  int) (s[i] - '0'));
        result = add_op(result, cur_digit);
    }

    *x = result;
    free(s);
}




//выводит число в двоичном виде в обратном порядке разрядов
void bin_exp(uint1024_t x){
    x.index = find_index(x);
    for(int i = 0; i <= x.index; ++i){
        printf("%d", (x.n[i / 8] >> (7 - i % 8 )) & 1);
    }

    printf("\n");
}

int main(void) {
    uint1024_t a = init();
    uint1024_t b = init();
    uint1024_t sum = init();
    uint1024_t sub = init();
    uint1024_t mult = init();
}