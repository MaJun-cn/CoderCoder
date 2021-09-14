#include <iostream>
#include <string>

std::string add_binary(const std::string& x_str, const std::string& y_str) {
    std::string res;
    int x_index = x_str.size() - 1;
    int y_index = y_str.size() - 1;
    int carry = 0;
    while (x_index >= 0 || y_index >= 0) {
        int cur_opx = 0;
        int cur_opy = 0;
        if (x_index >= 0) {
            cur_opx = x_str[x_index--] - '0';
        }
        if (y_index >= 0) {
            cur_opy = y_str[y_index--] - '0';
        }
        int cur_sum = cur_opx + cur_opy + carry;
        printf("cur_opx:%d, cur_opy:%d, carry:%d, cur_opr:%d\n", cur_opx, cur_opy, carry, cur_sum);
        if (cur_sum >= 2) {
            carry = 1;
            cur_sum -= 2;
        } else {
            carry = 0;
        }
        res += '0' + cur_sum;
    }
    if (carry == 1) {
        res += '1';
    }
    std::reverse(res.begin(), res.end());
    return res;
}

int main (){
    std::string x = "11111101";
    std::string y = "1110000";
    printf("%s + %s = %s\n", x.c_str(), y.c_str(), add_binary(x, y).c_str());
}
