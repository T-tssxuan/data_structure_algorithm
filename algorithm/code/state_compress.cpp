#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>

/**
 * Using the state compression.
 * Current position influenced by row_i and row_i+1
 * Using bitset to record the state
 */

using namespace std;
using ll = long long;
#define MOD(x) ((x) % 1000000007)
class Solution {
public:
    ll gretResult(ll n, ll m) {
        int state = 1 << (m * 2);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(state, 0)));
        int thresh = 1 << m;
        int tmp = 0;
        int suf_mask = (1 << m) - 1;
        int pre_mask = suf_mask << m;
        int pre, suf;
        for (int i = 0; i < thresh; ++i) {
            dp[n - 1][m - 1][pre_mask | i] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (i == n - 1 && j == m - 1) {
                    continue;
                }
                for (int s = state - 1; s >= 0; --s) {
                    tmp = 0;
                    pre = (pre_mask & s) >> m;
                    suf = (suf_mask & s);
                    int pos = m - j - 1;
                    // Current position is occupied
                    if (pre & (1 << pos)) {
                        dp[i][j][s] = j == m - 1? dp[i + 1][0][(s & suf_mask) << m] : dp[i][j + 1][s];
                    } else {
                        // Current position can place a cake horizoned
                        if ((j < m - 1)
                                && (pre & (1 << pos)) == 0
                                && (pre & (1 << (pos - 1))) == 0) {
                            tmp = pre;
                            tmp |= 1 << pos;
                            tmp |= 1 << (pos - 1);
                            tmp = (tmp << m) | suf;
                            dp[i][j][s] += dp[i][j][tmp];
                            dp[i][j][s] = MOD(dp[i][j][s]);
                        }
                        // Current position can place a cake vertical
                        if ((i < n - 1)
                                && (pre & (1 << pos)) == 0
                                && (suf & (1 << pos)) == 0) {
                            tmp = pre;
                            tmp |= 1 << pos;
                            tmp = (tmp << m) | suf;
                            tmp |= 1 << pos;
                            dp[i][j][s] += dp[i][j][tmp];
                            dp[i][j][s] = MOD(dp[i][j][s]);
                        }
                    }
                }
            }
        }
        return dp[0][0][0];
    }
};

int main() {
    Solution so;
    ll n, m;
    cin >> n >> m;
    auto ans = so.gretResult(n, m);
    cout << ans << endl;
    return 0;
}
