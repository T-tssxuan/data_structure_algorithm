#include <string>
#include <vector>
#include <iostream>
using namespace std;

/**
 * Descirbe: Implement wildcard pattern matching with support for '?' and '*'.
 *
 * Using dynamic programming get an O(len(s) * len(p)) algorithm
 */

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        // About the empty string.
        if (!s && !p) {
            return true;
        }
        if (!p) {
            return false;
        }

        const char *s_cur = s;
        const char *p_cur = p;
        int s_len = 0;
        int p_len = 0;
        // Get the length of the two string.
        while (*s_cur != '\0') {
            ++s_len;
            ++s_cur;
        }
        while (*p_cur != '\0') {
            ++p_len;
            ++p_cur;
        }

        // Record the preceding information.
        vector<vector<bool>> dp(p_len + 1, vector<bool>(s_len + 1, false));

        dp[0][0] = true;
        for (int i = 1; i <= p_len; ++i) {
            if (*(p + i - 1) == '*') {
                for (int j = 0; j <= s_len; ++j) {
                    // The following is matched obviously.
                    if (dp[i - 1][j]) {
                        for (int k = j; k <= s_len; ++k) {
                            dp[i][k] = true;
                        }
                        break;
                    }
                }
            } else if (*(p + i - 1) == '?') {
                for (int j = 0; j < s_len; ++j) {
                    // Based on the previous one.
                    if (dp[i - 1][j]) {
                        dp[i][j + 1] = true;
                    }
                }
            } else {
                for (int j = 1; j <= s_len; ++j) {
                    // Based on the previous one.
                    if (dp[i - 1][j - 1] && *(p + i - 1) == *(s + j - 1)) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        return dp[p_len][s_len];
    }
};

int main() {
    Solution so;
    string p, s;
    while (cin >> s) {
        cin >> p;
        auto re = so.isMatch(s.c_str(), p.c_str());
        cout << "result: " << re << endl;
    }
    return 0;
}
