#include <vector>
using namespace std;
// solution1:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int num_len = nums.size();
        if (num_len == 0) return 0;
        vector<int> dp(num_len, 0);
        int res = 0;
        for (int i = 0; i < num_len; ++i) {
            dp[i] = 1;
            int cur_max = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && cur_max < dp[j]) {
                    cur_max = dp[j];  
                }
            }
            dp[i] = cur_max + 1;
            if (dp[i] > res) res = dp[i];
        }
        return res;
    }
};
// solution2:
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len == 0) {
            return 0;
        }
        vector<int> b(nums_len + 1, 0);
        int res_len = 1;
        b[1] = nums[0];
        for (int i = 0; i < nums_len; ++i) {
            if (b[res_len] < nums[i]) {
                b[++res_len] = nums[i];
            } else {
                int left = 1;
                int right = res_len;
                int pos = 0;
                while (left <= right) {
                    int mid = (left + right) >> 1;
                    if (b[mid] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                b[pos + 1] = nums[i];
            }
        }
        return res_len;
    }
};

// https://leetcode-cn.com/problems/longest-increasing-subsequence/

// Derivative:

class Solution {

public:
    int findNumberOfLIS(vector<int>& nums) {
        int nums_len = nums.size();
        if (nums_len == 0) return 0;
        int res_num = 0;
        int max_slen = 0;
        vector<int> dp(nums_len, 0);
        vector<int> cnt(nums_len, 0);
        for (int i = 0; i < nums_len; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (dp[i] == dp[j] + 1) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (max_slen < dp[i]) {
                max_slen = dp[i];
                res_num = cnt[i];
            } else if (max_slen == dp[i]) {
                res_num += cnt[i];
            }
        }
        return res_num;
    }
};
// https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/submissions/