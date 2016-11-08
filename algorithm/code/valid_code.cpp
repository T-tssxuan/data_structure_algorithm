#include <string>
#include <iostream>
#include <vector>
using namespace std;

/**
 * Describe: Validate if a given string is numeric.
 */

class Solution {
public:
    bool isNumber(string& s) {
        if (s.size() == 0) {
            return false;
        }
        int len = s.size();
        int start = 0;
        int end = len - 1;

        // preceding zeros
        while (start < len && s[start] == ' ') {
            ++start;
        }

        // padding zeros
        while (end >= 0 && s[end] == ' ') {
            --end;
        }

        // The signed number
        if (s[start] == '+' || s[start] == '-') {
            ++start;
        }

        int state = 0;
        for (int i = start; i <= end; ++i) {
            // ecounter numbers
            if (s[i] >= '0' && s[i] <= '9') {
                if (state == 0) { // numbers at the begining
                    state = 1;
                } else if (state == 2 || state == 6) { // after period
                    state = 3;
                } else if (state == 4) { // after character 'e'
                    state = 5;
                }
            } else if (s[i] == '.') {
                if (state == 0) { // period at the beginning
                    state = 2;
                } else if (state == 1) { // period at the middle of the string
                    state = 6;
                } else {
                    return false;
                }
            } else if (s[i] == 'e') {
                if (state == 1 || state == 3) { // 'e' after number
                    state = 4;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        // valid state
        if (state == 1 || state == 3 || state == 5 || state == 6) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution so;
    string str;
    vector<int> test;
    while (cin >> str) {
        auto re = so.isNumber(str);
        cout << "result; " << re << endl;
    }
    return 0;
}
