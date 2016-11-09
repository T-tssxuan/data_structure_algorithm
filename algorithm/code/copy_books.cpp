#include <iostream>
#include <vector>
using namespace std;

/**
 * Describe: Given an array A of integer with size of n( means n books and 
 * number of pages of each book) and k people to copy the book. You must 
 * distribute the continuous id books to one people to copy. (You can give book 
 * A[1],A[2] to one people, but you cannot give book A[1], A[3] to one people, 
 * because book A[1] and A[3] is not continuous.) Each person have can copy one 
 * page per minute. Return the number of smallest minutes need to copy all the 
 * books.
 */

class Solution {
public:
    int copyBooks(vector<int> &pages, int k) {
        if (pages.size() == 0) {
            return 0;
        }
        int len = pages.size();
        if (len <= k) {
            return *max_element(pages.begin(), pages.end());
        }

        // dp[x][y] represent the minimal value for x people process the 
        // first y books.
        vector<vector<int>> dp(k + 1, vector<int>(len + 1, 0));
        int sum = 0;
        int idx;
        int pre;
        int cur_max;
        for (int i = 1; i <= k; ++i) {
            idx = i;
            pre = i - 1;
            sum = 0;
            cur_max = dp[i - 1][pre];
            while (idx <= len) {
                sum += pages[idx - 1];
                // when the dp[i - 1][pre + 1] less than sum, and we can make
                // sure that the dp[i - 1][pre + 1] is the minimal value for
                // dp[i][idx], because when we backtract the sum will increase
                // and greater than dp[i - 1][pre + 1], when we forward the pre
                // index, the dp[i - 1][pre + 1 + x] will greater than current 
                // value.
                while (i != 1 && pre < idx - 1 && dp[i - 1][pre + 1] < sum) {
                    ++pre;
                    sum -= pages[pre - 1];
                }

                // current max is the maximum value of the three
                cur_max = max(max(dp[i - 1][pre], sum), cur_max);
                dp[i][idx] = cur_max;
                ++idx;
            }
        }
        return dp[k][len];
    }
};

int main() {
    Solution so;
    int n, k;
    vector<int> test;
    while (cin >> n) {
        cin >> k;
        test = vector<int>(n, 0);
        for (auto &ele : test) {
            cin >> ele;
        }
        auto re = so.copyBooks(test, k);
        cout << "result: " << re << endl;
    }
    return 0;
}
