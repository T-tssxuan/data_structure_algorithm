#include <cstring>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int len = A.size();
        int idx = 0;
        while (idx < len) {
            if (A[idx] > 0 && A[idx] <= len && idx + 1 != A[idx]
                    && A[idx] != A[A[idx] - 1]) {
                swap(A[idx], A[A[idx] - 1]);
            } else {
                idx++;
            }
        }
        for (int i = 0; i < len; i++) {
            if (i + 1 != A[i]) {
                return i + 1;
            }
        }
        return len + 1;
    }
};

int main() {
    Solution so;
    vector<int> test;
    vector<vector<int>> matrix;
    int n, m;
    int tmp;
    while (cin >> n) {
        cin >> m;
        matrix = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        auto re = so.printZMatrix(matrix);
        cout << "result: ";
        for (auto ele : re) {
            cout << ele << ", ";
        }
        cout << endl;
    }
    return 0;
}
