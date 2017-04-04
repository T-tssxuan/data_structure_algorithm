#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <random>
#include <unordered_set>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;


using ll = long long;
using vvl = vector<vector<ll>>;

class Solution {
public:
    string collapse(string &src, vector<vector<string>> &dp, int i, int j) {
        auto tmp = src.substr(i, j - i + 1);
        auto idx = (tmp + tmp).find(tmp, 1);
        if (idx == string::npos) {
            return tmp;
        }
        return to_string(tmp.size() / idx) + "[" + dp[i][i + idx - 1] + "]";
    }
    string encode(string s) {
        int len = s.size();
        vector<vector<string>> dp(s.size(), vector<string>(s.size(), ""));
        for (int step = 0; step < len; ++step) {
            for (int i = 0; i + step < len; ++i) {
                int j = i + step;
                dp[i][j] = s.substr(i, j - i + 1);
                for (int k = i; k < j; ++k) {
                    auto left = dp[i][k];
                    auto right = dp[k + 1][j];
                    if (left.size() + right.size() < dp[i][j].size()) {
                        dp[i][j] = left + right;
                    }
                }
                auto tmp = collapse(s, dp, i, j);
                if (tmp.size() < dp[i][j].size()) {
                    dp[i][j] = tmp;
                }
            }
        }
        return dp[0][len - 1];
    }
};

int main() {
    Solution so;
    string str = "aaaaaabbbbbbaabbaabbccddccddccdd";
    cin >> str;
    auto rst = so.encode(str);
    cout << rst << endl;
    return 0;
}
