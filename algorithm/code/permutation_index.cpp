#include <iostream>
#include <vector>
#include <map>
using namespace std;

/**
 * Descirbe: Given a series of element, find its index in all permutation.
 * Suppose the index start at 1.
 *
 * permutationIndex: no duplicated element in the array.
 * permutationIndexII: there are duplicated elements.
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
    long long permutationIndexII(vector<int>& A) {
        map<int, int> record;

        // Get the duplicated information
        for (auto ele : A) {
            if (record.find(ele) == record.end()) {
                record[ele] = 0;
            }
            ++record[ele];
        }

        long long total = 1;
        for (auto ele : record) {
            total *= getDet(ele.second);
        }
        return getPermutationII(A, record, 0, A.size() - 1, total) + 1;
    }
    long long getPermutationII(vector<int>& A, map<int, int>& record, int start, 
            int end, long long total) {
        if (start > end) {
            return 0;
        }
        --record[A[start]];
        long long sum = 0;
        long long multi = 1;
        long long div = 1;
        map<int, bool> less;

        // count the element which less than the beginning.
        for (int i = start + 1; i <= end; ++i) {
            if (A[start] > A[i]) {
                less[A[i]] = true;
            }
            multi *= (i - start);
        }
        div = total;
        for (auto ele : less) {
            if (record[ele.first] == 1) {
                sum += multi / div;
            } else {
                // If get duplicated, need to change the divider.
                int tmp = div / getDet(record[ele.first]);
                tmp *= getDet((record[ele.first] - 1));
                sum += multi / tmp;
            }
        }

        // Calculated the next position duplicated sum.
        if (record[A[start]] > 0) {
            total = total / getDet((record[A[start]] + 1)) * getDet(record[A[start]]);
        }
        sum += getPermutationII(A, record, start + 1, end, total);
        return sum;
    }
    long long getDet(int k) {
        long long sum = 1;
        for (int i = 1; i <= k; ++i) {
            sum *= i;
        }
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
        auto re1 = so.permutationIndex(test);
        cout << "result: " << re1 << endl;
        auto re2 = so.permutationIndexII(test);
        cout << "result: " << re2 << endl;
    }
    return 0;
}
