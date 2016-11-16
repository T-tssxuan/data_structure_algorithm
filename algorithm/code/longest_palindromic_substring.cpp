#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Describe: Find the longest palindromic substring from a give string.
 */

class Solution {
public:
    int getLongestPalindrome(string &str) {
        if (str.size() == 0) return 0;
        string rst = addBoundaries(str);
        int len = rst.length();

        // center is i and the longest palindrome is [i - rad[i], i + rad[i]]
        vector<int> rad(len, 0);         
        // r is the right most current visited, and the c is the corresponded 
        // center
        int c = 0, r = 0;
        int m = 0, n = 0;
        for (int i = 0; i < len; ++i) {
            if (i > r) {
                rad[i] = 0;
                m = i - 1;
                n = i + 1;
            } else {
                int i2 = 2 * c - i;
                if (rad[i2] < r - i) {
                    // this is means there is no possible to expanding rad[i]
                    rad[i] = rad[i2];
                    m = -1;
                } else {
                    // the rad[i] is expandable
                    rad[i] = r - i;
                    n = r + 1;
                    m = 2 * i - n;
                }
            }
            // expanding the rad[i]
            while (m >= 0 && n < len && rst[m] == rst[n]) {
                ++rad[i];
                --m;
                ++n;
            }
            // update the rightmost position and the correspond center
            if (i + rad[i] > r) {
                c = i;
                r = i + rad[i];
            }
        }
        int re = 0, center = 0;
        for (int i = 0; i < len; ++i) {
            if (re < rad[i]) {
                re = rad[i];
                center = i;
            }
        }
        return re;
    }
    string addBoundaries(string &str) {
        string rst(str.size() * 2 + 1, '|');
        for (size_t i = 0; i < str.length(); ++i) {
            rst[i * 2 + 1] = str[i];
        }
        return rst;
    }
};

int main() {
    Solution so;
    int n;
    cin >> n;
    string str;
    while (n-- > 0) {
        cin >> str; 
        int re = so.getLongestPalindrome(str);
        cout << re << endl;
    }
    return 0;
}
