#include <string>

std::string int_to_binary(int n) {
    std::string result;
    while(n > 0) {
        int digit = n % 2;
        result = std::to_string(digit) + result;
        n /= 2;
    }
    return result;
}