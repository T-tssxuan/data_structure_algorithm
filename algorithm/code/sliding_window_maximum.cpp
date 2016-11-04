#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * Describe: Given an array of number and a window with size k, the window 
 * slides from left to right, find maximum value at the window at each sliding.
 */

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> q(k);
        int len = nums.size();
        vector<int> rst;
        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        for (int i = k; i < len; ++i) {
            rst.push_back(nums[q.front()]);
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        if (!nums.empty()) {
            rst.push_back(nums[q.front()]);
        }
        return rst;
    }
};


int main() {
    Solution so;
    vector<int> test;
    int n, k;
    while (cin >> n) {
        cin >> k;
        test = vector<int>(n);
        for (auto& ele : test) {
            cin >> ele;
        }
        auto re = so.maxSlidingWindow(test, k);
        for (auto ele : re) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
