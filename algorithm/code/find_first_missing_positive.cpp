#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Describe: Find the first missing positive number.
 * Do it in O(n)
 */

class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int len = A.size();
        int idx = 0;

        // Make the correspond element to it correspond position in array.
        while (idx < len) {
            if (A[idx] > 0 && A[idx] <= len && idx + 1 != A[idx]
                    && A[idx] != A[A[idx] - 1]) {
                swap(A[idx], A[A[idx] - 1]);
            } else {
                idx++;
            }
        }
        
        // Find the first missing number
        for (int i = 0; i < len; i++) {
            if (i + 1 != A[i]) {
                return i + 1;
            }
        }

        // Not found, returns len + 1
        return len + 1;
    }
};

int main() {
    Solution so;
    vector<int> test;
    int n;
    while (cin >> n) {
        test = vector<int>(n);
        for (int i = 0; i < n; ++i) {
            cin >> test[i];
        }
        int re = so.firstMissingPositive(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
