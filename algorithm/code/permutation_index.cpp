#include <iostream>
#include <vector>
using namespace std;

/**
 * Descirbe: Given a series of element, find its index in all permutation.
 * Suppose the index start at 1.
 */

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        return getPermutation(A, 0, A.size() - 1) + 1;
    }
    long long getPermutation(vector<int>& A, int start, int end) {
        if (start > end) {
            return 0;
        }
        int less = 0;
        long long sum = 1;
        for (int i = start + 1; i <= end; ++i) {
            if (A[start] > A[i]) {
                less++;
            }
            sum *= (i - start);
        }
        sum = less * sum;
        sum += getPermutation(A, start + 1, end);
        return sum;
    }
};

int main() {
    Solution so;
    vector<int> test;
    int n;
    while (cin >> n) {
        test = vector<int>(n);
        for (auto& ele : test) {
            cin >> ele;
        }
        auto re = so.permutationIndex(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
