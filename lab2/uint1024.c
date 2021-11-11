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

int main(void) {
    uint1024_t a = init();
    uint1024_t b = init();
    uint1024_t sum = init();
    uint1024_t sub = init();
    uint1024_t mult = init();
}