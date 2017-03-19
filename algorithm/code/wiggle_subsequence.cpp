#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Describle: Given a sequence and get the maximum wiggle subsequence length
 *
 * Solution: Using dynamic programming.
 */

class Solution {
public:
    struct Element {
        int count;
        int value;
    };
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        vector<pair<Element, Element>> record(nums.size() + 1);
        record[0].first.count = 1;
        record[0].first.value = nums[0];
        record[0].second.count = 1;
        record[0].second.value = nums[0];
        for (size_t i = 0; i < nums.size(); ++i) {
            record[i + 1].first.count = record[i].first.count;
            record[i + 1].first.value = record[i].first.value;
            if (nums[i] < record[i].first.value) {
                record[i + 1].first.value = nums[i];
            }
            if (nums[i] < record[i].second.value
                    && record[i + 1].first.count <= record[i].second.count) {
                record[i + 1].first.count = record[i].second.count + 1;
                record[i + 1].first.value = nums[i];
            }
            
            record[i + 1].second.count = record[i].second.count;
            record[i + 1].second.value = record[i].second.value;
            if (nums[i] > record[i].second.value) {
                record[i + 1].second.value = nums[i];
            }
            if (nums[i] > record[i].first.value
                    && record[i + 1].second.count <= record[i].first.count) {
                record[i + 1].second.count = record[i].first.count + 1;
                record[i + 1].second.value = nums[i];
            }
        }
        return max(record.back().first.count, record.back().second.count);
    }
};

int main() {
    Solution so;
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int rst = so.wiggleMaxLength(nums);
    cout << rst << endl;
    return 0;
}
