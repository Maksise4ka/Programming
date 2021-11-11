#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include "char10.h"

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

// определяет размер числа
int find_index(uint1024_t x){

  for(int i = 1024; i >= 0; -- i){
    int cur = (x.n[i / 8] >> (7 - i % 8)) & 1;
      if (cur)
        return i;
  }
  return 0;

}

uint1024_t from_uint(unsigned int x){
    uint1024_t num = init();
    while (x != 0){
        int cur = num.index;
        num.n[cur / 8] = (char) ((num.n[cur / 8] >> (7 - cur % 8)) | (x % 2)) << (7 - cur % 8);
        num.index ++;
        x /= 2;
    }
    num.index --;

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