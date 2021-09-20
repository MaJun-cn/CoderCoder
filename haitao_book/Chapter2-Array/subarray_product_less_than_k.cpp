#include <iostream>
#include <algorithm>
#include <vector>
int NumSubArrayProductLessThanK(int target, std::vector<int>& nums) {
    int nums_len = nums.size();
    if (nums_len == 0) return 0;
    int left = 0;
    int right = 0;
    int product = 1;
    int count = 0;
    for (int right = 0; right < nums_len; ++right) {
        product *= nums[right];
        while (left <= right && product >= target) {
            product /= nums[left++];
        }
        count += right >= left ? right - left + 1 : 0;
    }
    return count;
}
int main () {
    std::vector<int> nums = {10, 5, 2, 6};
    int key = 100;
    std::cout << NumSubArrayProductLessThanK(key, nums) << std::endl;

}