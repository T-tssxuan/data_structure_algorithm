#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Describe: Describe: Given a positive integer N, it is possible to represent N 
 * as the sum of several positive or negative powers of 2 (± 2k for some k). For 
 * example can be represented as 22 + 21 + 20 and 23 + (-20). 
 * Your task is to find the representation which contains the minimum powers of
 * 2.
 */

class Solution {
public:
    int minNumberOfPower(int n) {
        int len = 1;
        int tmp = n;
        // Get the length of the binary sequece
        while (tmp >>= 1) {
            ++len;
        }
        int ones = 0;
        int zeros = 0;
        int pre_zeros = 0;
        int rst = 0;
        for (int i = 0; i < len; ++i) {
            if (n & (1 << i)) {
                // if get one at this position
                if (pre_zeros >= 2) {
                    // number of consecutive zeros greater than 2
                    tmp = 2 + zeros;
                    rst += ones < tmp? ones : tmp;
                    ones = 1;
                    zeros = 0;
                } else {
                    // number of consecutive zeros not greater than 2
                    if (ones > 0) {
                        zeros += pre_zeros;
                    }
                    ++ones;
                }
                pre_zeros = 0;
            } else {
                ++pre_zeros;
            }
        }
        tmp = 2 + zeros;
        rst += ones < tmp? ones : tmp;
        return rst;
    }
};

int main() {
    Solution so;
    int n;
    while (cin >> n) {
        int len = so.minNumberOfPower(n);
        cout << len << endl;
    }
    return 0;
}
