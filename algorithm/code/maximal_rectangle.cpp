#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

/**
 * Desribe: Given a 2D boolean matrix filled with False and True, find the largest
 * rectangle containing all True and return its area.
 */

class Solution {
public:
    int maximalRectangle(vector<vector<bool> > &matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> record(cols, 0);
        // stack to record the column with consecutive True more than current
        // column
        stack<pair<int, int>> his;
        int max = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j]) {
                    record[j] += 1;
                } else {
                    record[j] = 0;
                }
                int cum = 0;
                // pop all columns with height greater or equal to current.
                while (!his.empty() && his.top().first >= record[j]) {
                    int tmp = his.top().first * (his.top().second + cum);
                    max = max > tmp? max : tmp;
                    cum += his.top().second;
                    his.pop();
                }
                if (record[j] > 0) {
                    his.push(make_pair(record[j], cum + 1));
                }
            }
            int cum = 0;
            // empty the stack
            while (!his.empty()) {
                int tmp = his.top().first * (his.top().second + cum);
                max = max > tmp? max : tmp;
                cum += his.top().second;
                his.pop();
            }
        }
        return max;
    }
};

int main() {
    Solution so;
    vector<vector<bool>> test;
    int rows, cols;
    int tmp;
    while (cin >> rows) {
        cin >> cols;
        test = vector<vector<bool>>(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < rows; ++j) {
                cin >> tmp;
                test[i][j] = tmp == 0? false : true;
            }
        }
        auto re = so.maximalRectangle(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
