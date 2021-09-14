#include <iostream>
#include <vector>

void count_bits_1(int num) {
    std::vector<int> res;
    res.resize(num);
    res[0] = 0;
    for (int i = 1; i <= num; ++i) {
        int cur_num = i;
        int counter = 0;
        while (cur_num > 0) {
            cur_num = cur_num & (cur_num - 1);
            ++counter;
        }
        res[i] = counter;
        printf("vec[%d]=%d ", i, res[i]);
    }
    printf("\n");
}

void count_bits_2(int num) {
    std::vector<int> res;
    res.resize(num);
    res[0] = 0;
    for (int i = 1; i <= num; ++i) {
        res[i] = res[i & (i-1)] + 1;
        printf("vec[%d]=%d ", i, res[i]);
    }
    printf("\n");
}

void count_bits_3(int num) {
    std::vector<int> res;
    res.resize(num);
    res[0] = 0;
    for (int i = 1; i <= num; ++i) {
        res[i] = res[i >> 1] + (i & 1);
        printf("vec[%d]=%d ", i, res[i]);
    }
    printf("\n");
}

int main () {
    count_bits_1(100); 
    count_bits_2(100); 
    count_bits_3(100); 
}
