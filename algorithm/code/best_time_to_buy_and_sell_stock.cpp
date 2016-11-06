#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Describe: Say you have an array for which the ith element is the price of a
 * given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions
 */


class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        int len = prices.size();
        if (k >= len) {
            int rst = 0;
            for (int i = 1; i < len; ++i) {
                if (prices[i] > prices[i - 1]) {
                    rst += prices[i] - prices[i - 1];
                }
                return rst;
            }
        }
        // At index i happened transaction at most j times.
        vector<vector<int>> global(len, vector<int>(k + 1, 0));
        // The jth selling existed at index i.
        vector<vector<int>> local(len, vector<int>(k + 1, 0));
        for (int i = 1; i < len; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; ++j) {
                local[i][j] = max(global[i - 1][j - 1], local[i - 1][j] + diff);
                global[i][j] = max(global[i - 1][j], local[i][j]);
            }
        }
        return global[len - 1][k];
    }
};

int main() {
    Solution so;
    int n, k;
    vector<int> test;
    while (cin >> k) {
        cin >> n;
        test = vector<int>(n);
        for (auto &ele : test) {
            cin >> ele;
        }
        auto re = so.maxProfit(k, test);
        cout << "result: " << re << endl;
    }
    return 0;
}
