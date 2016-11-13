#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Describe: Write a program to find the nth super ugly number.
 * Super ugly numbers are positive numbers whose all prime factors are in the 
 * given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 
 * 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given 
 * primes = [2, 7, 13, 19] of size 4.
 */

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        sort(primes.begin(), primes.end());
        vector<long long> dp(n, 1);
        vector<int> idx(primes.size(), 0);
        dp[0] = 1;
        int len = primes.size();
        for (int i = 1; i < n; ++i) {
            dp[i] = INT_MAX;
            for (int j = 0; j < len; ++j) {
                dp[i] = min(dp[i], dp[idx[j]] * primes[j]);
            }
            for (int j = 0; j < len; ++j) {
                if (dp[i] == dp[idx[j]] * primes[j]) {
                    ++idx[j];
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution so;
    int n, k;
    vector<int> test;
    while (cin >> n) {
        test = vector<int>(n, 0);
        for (auto &ele : test) {
            cin >> ele;
        }
        cin >> k;
        auto re = so.nthSuperUglyNumber(k, test);
        cout << "result: " << re << endl;
    }
    return 0;
}
