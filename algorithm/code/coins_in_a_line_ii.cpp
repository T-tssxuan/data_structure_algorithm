#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool firstWillWin(vector<int> &values) {
        if (values.size() == 0) {
            return 0;
        }
        int sum = 0;
        for (auto ele : values) {
            sum += ele;
        }
        
        // pair.first: the max value it can get, pair.second: method which he
        // used to get the max value.
        vector<pair<int, int>> dp(values.size(), make_pair(0, 0));
        vector<bool> state(values.size(), false);
        getMax(values, dp, state, 0);
        return dp[0].first > sum - dp[0].first? true : false;
    }
    int getMax(vector<int> &values, vector<pair<int, int>> &dp, 
            vector<bool> &state, size_t idx) {
        if (idx >= values.size()) {
            return 0;
        }
        if (state[idx]) {
            return dp[idx].first;
        }
        state[idx] = true;

        // If the is left one or two coins, we can get them all
        if (idx + 1 >= values.size()) {
            dp[idx].first = values[idx];
            dp[idx].second = 1;
            return dp[idx].first;
        }
        if (idx + 2 >= values.size()) {
            dp[idx].first = values[idx] + values[idx + 1];
            dp[idx].second = 2;
            return dp[idx].first;
        }

        // Make sure the next and the next after next result is calculated.
        getMax(values, dp, state, idx + 1);
        getMax(values, dp, state, idx + 2);

        // Get the result of using method 1
        int max1 = values[idx];
        if (dp[idx + 1].second == 1) {
            max1 += getMax(values, dp, state, idx + 2);
        } else {
            max1 += getMax(values, dp, state, idx + 3);
        }

        // Get the result of using method 2
        int max2 = values[idx] + values[idx + 1];
        if (dp[idx + 2].second == 1) {
            max2 += getMax(values, dp, state, idx + 3);
        } else {
            max2 += getMax(values, dp, state, idx + 4);
        }

        // The better one of the two method is the result
        if (max1 > max2) {
            dp[idx].first = max1;
            dp[idx].second = 1;
        } else {
            dp[idx].first = max2;
            dp[idx].second = 2;
        }
        return dp[idx].first;
    }
};

int main() {
    Solution so;
    int n;
    vector<int> test;
    while (cin >> n) {
        test = vector<int>(n);
        for (auto &ele : test) {
            cin >> ele;
        }
        auto re = so.firstWillWin(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
