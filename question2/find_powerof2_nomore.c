#include <stdio.h>
#include <stdlib.h>

void print16bit(u_int16_t N){
    int maxPower = 1 << 15;
    for(int i = 15; i >= 0; i--){
        printf("%d", N&maxPower ? 1 : 0);
        maxPower = maxPower >> 1;
    }
    printf("\n");
}
u_int16_t func(u_int16_t N) {
    /* change all right side bits to 1 */
    print16bit(N);
    print16bit(N >> 1);
    N |= N >> 1;
    printf("----------------\n");
    print16bit(N);
    printf("\n");
    print16bit(N);
    print16bit(N >> 2);
    N |= N >> 2;
    printf("----------------\n");
    print16bit(N);
    printf("\n");
    print16bit(N);
    print16bit(N >> 4);
    N |= N >> 4;
    printf("----------------\n");
    print16bit(N);
    printf("\n");
    print16bit(N);
    print16bit(N >> 8);
    N |= N >> 8;
    printf("----------------\n");
    print16bit(N);
    printf("\n");
    printf("(N + 1) = ");
    print16bit(N + 1);
    printf("(N + 1) >> 1 = ");
    print16bit((N + 1) >> 1);
    return (N + 1) >> 1;
}
int main(){
    u_int16_t a = 65535;
    // print16bit(a);
    a = func(a);
    printf("ans = %d", a);
}