#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

/** 
 * Describe: Given an unsorted array, find the maximum difference between the 
 * successive elements in its sorted form.  Try to solve it in linear 
 * time/space. Return 0 if the array contains less than 2 elements. All num is 
 * non-negative.
 * Solution:
 *     a. Using bucket.
 *     b. Each bucket get the maximum and the minimal.
 *     c. The gap to divide the bucket should no greater than the minimal gap well
 *        can get.
 */

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());
        int minVal = *min_element(nums.begin(), nums.end());
        int gap = (maxVal - minVal - 1) / (nums.size() - 1) + 1;
        vector<pair<int, int>> bucket(nums.size(), make_pair(maxVal, -1));
        int idx = 0;
        for (auto num : nums) {
            idx = (num - minVal) / gap;
            bucket[idx].first = min(bucket[idx].first, num);
            bucket[idx].second = max(bucket[idx].second, num);
        }

        int pre_max = minVal;
        int rst = 0;
        for (auto &ele : bucket) {
            if (ele.second == -1) {
                continue;
            }
            rst = max(rst, ele.first - pre_max);
            rst = max(rst, ele.second - ele.first);
            pre_max = ele.second;
        }
        return rst;
    }
};

int main() {
    Solution so;
    vector<int> nums = {1, 2, 3, 4, 10};
    int rst = so.maximumGap(nums);
    cout << rst << endl;
    return 0;
}
