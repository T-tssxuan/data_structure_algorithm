#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

/**
 * Describe: Given a positive integer n, find the least number of perfect square
 * numbers (for example, 1, 4, 9, 16, ...) which sum to n.
 */

class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        for (int a = 0; a * a <= n; ++a) {
            int b = sqrt(n - a * a);
            if (a * a + b * b == n) {
                return !!a + !!b;
            }
        }
        return 3;
    }
};

int main() {
    Solution so;
    int n;
    while (cin >> n) {
        auto re = so.numSquares(n);
        cout << "result: " << re << endl;
    }
    return 0;
}
