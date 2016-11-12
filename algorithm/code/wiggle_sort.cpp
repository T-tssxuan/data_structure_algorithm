#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * Describe: Given an unsorted array nums, reorder it such that
 * nums[0] < nums[1] > nums[2] < nums[3]....
 */
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        int mid = len / 2;
        findKthElement(nums, 0, len - 1, mid);
        mid = nums[mid];

        #define A(i) nums[(1+2*(i)) % (len|1)]
        int i = 0, j = 0, k = len - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
    void findKthElement(vector<int> &nums, int beg, int end, int k) {
        if (beg >= k) {
            return;
        }
        int part = partition(nums, beg, end);
        if (part < k - 1) {
            findKthElement(nums, part + 1, end, k);
        } else if (part > k - 1) {
            findKthElement(nums, beg, part - 1, k);
        }
    }
    int partition(vector<int> &nums, int lo, int hi) {
        // there sort be the lomuto partition
        int pivot = nums[hi];
        int beg = lo;
        int i = lo;
        while (i < hi) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[beg++]);
            }
            ++i;
        }
        swap(nums[beg], nums[hi]);
        return beg;
    }
};

int main() {
    Solution so;
    int n, k;
    vector<int> test;
    while (cin >> n) {
        test = vector<int>(n, 0);
        for (auto &ele : test) {
            cin >> ele;
        }
        so.wiggleSort(test);
        for (auto ele : test) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
