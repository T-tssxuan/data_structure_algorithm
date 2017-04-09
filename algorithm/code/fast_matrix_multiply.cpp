#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <iterator>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll MOD = 1000000007;


/**
 * Using fast matrix multiply and building the state transfer matrix.
 */


class Solution {
public:
    vector<pair<int, int>> offset = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, 
        {1, -2}, {-1, -2}, {-2, -1}};
    int len = 64;
    ll getRst(ll n, ll r, ll c) {
        --r;
        --c;
        vector<vector<ll>> mat(len, vector<ll>(1, 0));
        mat[r * 8 + c][0] = 1;
        auto tran = buildTransfer();
        vector<vector<ll>> cur(len, vector<ll>(len, 0));
        for (int i = 0; i < len; ++i) {
            cur[i][i] = 1;
        }
        /**
         * Fast matrix mult
         */
        while (n) {
            if (n & 1) {
                cur = mult(tran, cur);
            }
            tran = mult(tran, tran);
            n >>= 1;
        }
        mat = mult(cur, mat);
        int ans = 0;
        for (int i = 0; i < len; ++i) {
            ans = (ans + mat[i][0]) % MOD;
        }
        return ans;
    }
    /**
     * Building state transfer matrix.
     */
    vector<vector<ll>> buildTransfer() {
        vector<vector<ll>> tran(len, vector<ll>(len, 0));
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                for (auto ele : offset) {
                    int r = i + ele.first;
                    int c = j + ele.second;
                    if (r >= 0 && r < 8 && c >= 0 && c < 8) {
                        tran[i * 8 + j][r * 8 + c] = 1;
                    }
                }
            }
        }
        return tran;
    }
    /**
     * Matrix mult
     */
    vector<vector<ll>> mult(vector<vector<ll>> &vec1, vector<vector<ll>> &vec2) {
        int n = vec1.size();
        int m = vec2[0].size();
        int l = vec1[0].size();
        vector<vector<ll>> rst(n, vector<ll>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int k = 0; k < l; ++k) {
                    rst[i][j] = (rst[i][j] + vec1[i][k] * vec2[k][j] % MOD) % MOD;
                }
            }
        }
        return rst;
    }
};

int main() {
    ll n, r, c;
    cin >> n >> r >> c;
    Solution so;
    cout << so.getRst(n, r, c) << endl;
    return 0;
}
