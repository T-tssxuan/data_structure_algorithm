#include <iostream>
using namespace std;

/**
 * Describe: Given a series of coins, and two players. Each time their can flip 
 * x or y coins, decide the first player will win or lose.
 *
 * Suppose there always gets a result.
 */

class Solution {
public:
    bool firstWillWin(int n, int x, int y) {
        int sum = x + y;
        if (n % sum == 0) {
            return false;
        }
        int left = n % sum;
        if (left == x || x == y) {
            return true;
        }
        int less = x < y? x : y;
        return (left / less) % 2 == 1;
    }
};

int main() {
    Solution so;
    int n, x, y;
    while (cin >> n) {
        cin  >> x;
        cin >> y;
        auto re = so.firstWillWin(n, x, y);
        cout << "result: " << re << endl;
    }
    return 0;
}
