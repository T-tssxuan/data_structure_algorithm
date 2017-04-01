#include <iostream>
#include <vector>
#include <string>

using namespace std;

using ll = long long;
using vvl = vector<vector<ll>>;
using vl = vector<ll>;

class Solution {
public:
    ll MO = 1000000007;
    pair<int, ll> getRst(string &str) {
        int left = 0; // the left side end position
        int right = 0; // the right side end position
        int len = str.size();
        int cur = 0;
        int cc = 0;
        int left_cc = 0; // the left side missed parentheses
        int right_cc = 0; // the right side missed parentheses
        int total = 0; // total missed parentheses

        // Counting the missed parentheses one the left side or the right side
        while (cur < len) {
            if (str[cur] == '(') {
                ++cc;
            } else {
                --cc;
            }
            if (cc < 0) {
                left = cur;
                cc = 0;
                ++left_cc;
            }
            if (cc == 0) {
                right = cur + 1;
            }
            ++cur;
        }
        right_cc = cc;
        total = left_cc + right_cc;
        if (total == 0) {
            return pair<int, ll>(0, 1);
        }

        // Each segment ")....)" view as a component, and when ever we encounter
        // the descrease point which '(' less than ')' we need to descrease the
        // component element.
        vector<ll> dp(left_cc + 1, 0);
        dp[0] = 1;
        // current component and previous component a least get base element
        int base = 1;
        cc = 0;
        update(dp, base);
        for (int i = 0; i < left; ++i) {
            if (str[i] == '(') {
                ++cc;
            } else {
                --cc;
            }
            if (cc < 0) {
                cc = 0;
                ++base;
            }
            if (str[i] == ')') {
                update(dp, base);
            }
        }
        ll lm = dp.back();

        dp = vector<ll>(right_cc + 1, 0);
        dp[0] = 1;
        base = 1;
        update(dp, base);
        cc = 0;
        for (int i = len - 1; i > right; --i) {
            if (str[i] == ')') {
                ++cc;
            } else {
                --cc;
            }
            if (cc < 0) {
                cc = 0;
                ++base;
            }
            if (str[i] == '(') {
                update(dp, base);
            }
        }
        ll rm = dp.back();
        return pair<int, ll>(total, (lm * rm) % MO);
    }

    // update the dp array
    void update(vector<ll> &dp, int base) {
        int len = dp.size();
        ll acc = dp[base - 1];
        for (int i = base; i < len; ++i) {
            acc = (acc + dp[i]) % MO;
            dp[i] = acc;
        }
    }
};

int main() {
    string str;
    cin >> str;
    Solution so;
    auto rst = so.getRst(str);
    cout << rst.first << " " << rst.second << endl;
    return 0;
}
