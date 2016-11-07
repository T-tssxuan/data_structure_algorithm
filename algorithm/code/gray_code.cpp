#include <iostream>
#include <vector>
using namespace std;

/**
 * Describe: The gray code is a binary numeral system where two successive 
 * values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the 
 * code, find the sequence of gray code. A gray code sequence must begin with 0 
 * and with cover all 2n integers.
 */

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n <= 0) {
            return vector<int>();
        }
        vector<int> rst(2, 0);
        rst[0] = 0;
        rst[1] = 1;
        for (int i = 1; i < n; ++i) {
            int tmp = 1 << i;
            int j = (1 << i) - 1;
            // Scan back
            while (j >= 0) {
                rst.push_back(tmp | rst[j]);
                --j;
            }
        }
        return rst;
    }
};

int main() {
    Solution so;
    int n;
    vector<int> test;
    while (cin >> n) {
        auto re = so.grayCode(n);
        for (auto &ele : re) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
