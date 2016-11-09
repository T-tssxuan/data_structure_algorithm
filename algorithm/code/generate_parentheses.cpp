#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Describe: Given n pairs of parentheses, write a function to generate all 
 * combinations of well-formed parentheses.
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> rst;
        if (n <= 0) {
            return rst;
        }
        string cur;
        recusive(rst, cur, 0, 0, n);
        return rst;
    }
    void recusive(vector<string> &rst, string cur, int forward, int backward,
            int len) {
        // indicate all element is added
        if (backward == len) {
            rst.push_back(cur);
            return;
        }
        string str = cur;
        for (int i = forward + 1; i <= len; ++i) {
            cur.push_back('(');
            str = cur;
            for (int j = backward + 1; j <= i; ++j) {
                str.push_back(')');
                recusive(rst, str, i, j, len);
            }
        }
    }
};

int main() {
    Solution so;
    string str;
    vector<int> test;
    int n;
    while (cin >> n) {
        auto re = so.generateParenthesis(n);
        cout << "result: " << endl;
        for (auto &ele : re) {
            cout << ele << endl;
        }
    }
    return 0;
}
