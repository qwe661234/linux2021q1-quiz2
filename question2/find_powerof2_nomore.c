#include <stdio.h>
#include <stdlib.h>

u_int16_t func(u_int16_t N) {
    /* change all right side bits to 1 */
    N |= N >> 1;
    N |= N >> 2;
    N |= N >> 4;
    N |= N >> 8;
    return (N + 1) >> 1;
}

int main(){
    u_int16_t a = 21;
    a = func(a);
    printf("ans = %d", a);
}