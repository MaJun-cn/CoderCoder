#include <vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// 162. Find Peak Element
/*
利用双指针和爬山法，一直向上走，就可以站在山顶。
https://leetcode-cn.com/problems/find-peak-element/
*/