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

uint1024_t mult_op(uint1024_t x, uint1024_t y){
    uint1024_t result = init();
    
    for(int i = x.index; i >= 0; --i){
    
        int cur = (x.n[i / 8] >> (7 - i % 8)) & 1;

        if(cur){
            uint1024_t tmp = init();
            for(int j = 0; j <= y.index; ++j){
                int cury = (y.n[j / 8] >> (7 - j % 8)) & 1;
                int cur_index = i + j;
                tmp.n[cur_index / 8] = (char) ((tmp.n[cur_index / 8] >> (7 - cur_index % 8 )) | (cury)) << (7 - cur_index % 8);
            }

            result = add_op(result, tmp);
    }

  }

    result.index = find_index(result);

    return result;
}

int main(void) {
    uint1024_t a = init();
    uint1024_t b = init();
    uint1024_t sum = init();
    uint1024_t sub = init();
    uint1024_t mult = init();
}