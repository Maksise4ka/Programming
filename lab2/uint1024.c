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

uint1024_t subtr_op(uint1024_t x, uint1024_t y){
    uint1024_t result = init();
    int prev = 0;

    for(int i = 0; i < 128; ++i){

        for(int j = 0; j < 8; ++j){
      
            int digx = (x.n[i] >> (7 - j)) & 1;
            int digy = (y.n[i] >> (7 - j)) & 1;

            if ((digx && digy && !prev) || (digx && !digy && prev) || (!digx && !digy && !prev) || (!digx && digy && prev))
                result.n[i] = (char) ((result.n[i] >> (7 - j)) | (0)) << (7 - j);
            else
                result.n[i] = (char) ((result.n[i] >> (7 - j)) | (1)) << (7 - j);

            prev = 1 ?(digx < digy + prev) : 0;

            int cur = (result.n[i] >> (7 - j)) & 1;
            if (cur)
                result.index = 8 * i + j;

        }

    }

    if(prev == 1){
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