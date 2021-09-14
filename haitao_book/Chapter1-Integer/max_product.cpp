#include <iostream>
#include <vector>
#include <string>

int max_product(std::vector<std::string>& words) {
    int res = 0;
    int words_len = words.size();
    std::vector<int> bit_hash;
    bit_hash.resize(words_len);
    for (int i = 0; i < words_len; ++i) {
        for (auto ch : words[i]) {
            bit_hash[i] |= 1 << (ch - 'a');
        }
    }

    for (int i = 0; i < words_len; ++i) {
        for (int j = i+1; j < words_len; ++j) {
            if ((bit_hash[i] & bit_hash[j]) == 0) {
                res = std::max(res, int(words[i].size() * words[j].size()));
            }
        }
    }
    return res;
}

int main () {
    std::vector<std::string> nums = {"asdf","goaosoo", "lkja", "zsxclv"};
    printf("single_number: %d\n", max_product(nums));
}
