#include <iostream>
#include <vector>

int single_number(std::vector<int>& nums) {
    int sum_bit[32] = {0};
    for (auto num : nums) {
        for (int i = 0; i < 32; ++i) {
            sum_bit[i] += (num >> (31 - i)) & 1;
        }
    }
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        res = (res << 1) + (sum_bit[i] % 3);
    }
    return res;
}

int main () {
    std::vector<int> nums = {0,0,0,8,8,8,7,6,7,7};
    printf("single_number: %d\n", single_number(nums));
}