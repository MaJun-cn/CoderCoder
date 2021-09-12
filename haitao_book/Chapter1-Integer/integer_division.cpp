#include <iostream>

int devision_for_negative(int dividend, int divisor) {
    int res = 0;
    while (dividend <= divisor) {
        int cur_raito = 1;
        int op_v = divisor;
        while (op_v >= 0xc0000000 && divisor <= op_v + op_v) {
            cur_raito += cur_raito;
            op_v += op_v;
        }
        res += cur_raito;
        dividend -= op_v;
    }
    return res;
}

int devision(int dividend, int divisor){
    if (dividend == 0x80000000 && divisor == -1) {
        printf("error: result out of range");
        return 0;
    }
    int negative = 2;
    if (dividend > 0) {
        --negative;
        dividend = -dividend;
    }
    if (divisor > 0) {
        --negative;
        divisor = -divisor;
    }
    int result = devision_for_negative(dividend, divisor);
    return negative == 1 ? -result : result;
}
int main (){
    int x = 0X40000000;
    int y = 1;
    printf("%d / %d = %d\n", x, y, devision(x, y));
    // printf("mix int: %d \n", int(0x80000000));
}
