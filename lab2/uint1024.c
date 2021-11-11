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

uint1024_t add_op(uint1024_t x, uint1024_t y){
    uint1024_t result = init();
    int prev = 0;

    for(int i = 0; i < 128; ++i){

        for(int j = 0; j < 8; ++j){
            int digx = ((x.n[i] >> (7 - j)) & 1);
            int digy = ((y.n[i] >> (7 - j)) & 1);
      
            result.n[i] = (char) ((result.n[i] >> (7 - j) ) | ((digx + digy + prev) % 2)) << (7 - j);

            if ((digx && digy) || ((digx || digy) && prev))
                prev = 1;
            else
                prev = 0;
      
        int cur = (result.n[i] >> (7 - j)) & 1;
        if (cur)
            result.index = i * 8 + j;

    }

  }

    if (prev){
        printf("UB\n");
        return init();
    }

    return result;
}

int main(void) {
    uint1024_t a = init();
    uint1024_t b = init();
    uint1024_t sum = init();
    uint1024_t sub = init();
    uint1024_t mult = init();
}