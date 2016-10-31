#include <iostream>
#include <vector>
using namespace std;

/**
 * Describe: Given n balloons, indexed from 0 to n-1. Each balloon is painted 
 * with a number on it represented by array nums. You are asked to burst all the
 * balloons. If the you burst balloon i you will get:
 *         nums[left] * nums[i] * nums[right] coins.
 * Here left and right are adjacent indices of i. After the burst, the left and
 * right then becomes adjacent.
 * Find the maximum coins you can collect by bursting the balloons wisely.
 * - You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can
 *   not burst them.
 * - 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
 *
 * Solution: Using the dynamic programming.
 */
class Solution {
public:
    /**
     * @param nums a list of integer
     * @return an integer, maximum coins
     */  
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> dp(len + 2, vector<int>(len + 2, 0));
        int j = 0;
        for (int step = 0; step < len; ++step) {
            for (int i = 0; i < len - step; ++i) {
                j = i + step;
                int max = 0;
                int cur = 0;
                for (int idx = i; idx <= j; ++idx) {
                    cur = getMulti(nums, i - 1, idx, j + 1);
                    cur += dp[i + 1][idx] + dp[idx + 2][j + 1];
                    max = max > cur? max : cur;
                }
                dp[i + 1][j + 1] = max > dp[i + 1][j + 1]? \
                                   max : dp[i + 1][j + 1];
            }
        }
        return dp[1][len];
    }
    int getMulti(vector<int>& nums, int a, int b, int c) {
        int tmp1, tmp2, tmp3;
        tmp1 = a < 0? 1 : nums[a];
        tmp2 = nums[b];
        tmp3 = c >= static_cast<int>(nums.size())? 1 : nums[c];
        return tmp1 * tmp2 * tmp3;
    }
};




int main() {
    Solution so;
    vector<int> test;
    int n, tmp;
    while (cin >> n) {
        test.clear();
        while (n-- > 0) {
            cin >> tmp;
            test.push_back(tmp);
        }
        int re = so.maxCoins(test);
        cout << re << endl;
    }
    return 0;
}
