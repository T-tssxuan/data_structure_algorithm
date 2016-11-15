#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Describe: Given two arrays of length m and n with digits 0-9 representing two
 * numbers. Create the maximum number of length k <= m + n from digits of the 
 * two. The relative order of the digits from the same array must be preserved. 
 * Return an array of the k digits. You should try to optimize your time and 
 * space complexity.
 */

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> rst(k, 0);
        for (int i = 0; i <= k && i <= len1; ++i) {
            if (len2 >= k - i) {
                auto dp1 = getMax(nums1, i);
                auto dp2 = getMax(nums2, k - i);
                merge(rst, dp1, i, dp2, k - i, k);
            }
        }
        return rst;
    }
    void merge(vector<int> &rst, vector<int> &dp1, int len1, vector<int> &dp2, int len2, int k) {
        vector<int> tmp;
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < len1 && idx2 < len2) {
            if (compareTwoArray(dp1, idx1, len1, dp2, idx2, len2)) {
                tmp.push_back(dp1[idx1++]);
            } else {
                tmp.push_back(dp2[idx2++]);
            }
        }
        while (idx1 < len1) {
            tmp.push_back(dp1[idx1++]);
        }
        while (idx2 < len2) {
            tmp.push_back(dp2[idx2++]);
        }
        if (!compareTwoArray(rst, 0, k, tmp, 0, k)) {
            rst.swap(tmp);
        }
    }
    bool compareTwoArray(vector<int> &vec1, int beg1, int end1, 
            vector<int> &vec2, int beg2, int end2) {
        int idx1 = beg1;
        int idx2 = beg2;
        while (idx1 < end1 && idx2 < end2) {
            if (vec1[idx1] < vec2[idx2]) {
                return false;
            } else if (vec1[idx1] > vec2[idx2]) {
                return true;
            }
            ++idx1;
            ++idx2;
        }
        return idx1 != end1;
    }
    vector<int> getMax(vector<int> &vec, int k) {
        vector<int> rst(k, 0);
        int idx = 0;
        int len = vec.size();
        for (int i = 0; i < len; ++i) {
            while (idx > 0 && idx + len - i > k && vec[i] > rst[idx - 1]) {
                --idx;
            }
            if (idx < k) {
                rst[idx++] = vec[i];
            }
        }
        return rst;
    }
};

int main() {
    Solution so;
    vector<int> nums1;
    vector<int> nums2;
    int k, len1, len2;
    while (cin >> k) {
        cin >> len1;
        nums1 = vector<int>(len1, 0);
        for (auto &ele : nums1) {
            cin >> ele;
        }
        cin >> len2;
        nums2 = vector<int>(len2, 0);
        for (auto &ele : nums2) {
            cin >> ele;
        }
        auto re = so.maxNumber(nums1, nums2, k);
        cout << "result: "; 
        for (auto ele : re) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
