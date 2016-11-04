#include <iostream>
#include <vector>
using namespace std;

/**
 * Describe: Given n non-negative integers representing an elevation map where 
 * the width of each bar is 1, compute how much water it is able to trap after 
 * raining.
 */

class Solution {
public:
    int trapRainWater(vector<int> &heights) {
        int len = heights.size();
        if (len <= 1) {
            return 0;
        }
        int l_high = 0; // left higher
        int r_high = len - 1; // right higher
        int cum = 0;
        int cur = 0;
        int rst = 0;
        while (l_high < r_high) {
            if (heights[l_high] < heights[r_high]) {
                cur = l_high + 1;
                cum = 0;
                // find next element which greater than heights[l_hight] from 
                // front to end 
                while (cur < r_high && heights[cur] <= heights[l_high]) {
                    cum += heights[cur];
                    ++cur;
                }
                // elements in (l_high ... cur) can safely calculate
                rst += heights[l_high] * (cur - l_high - 1) - cum;
                l_high = cur;
            } else {
                cur = r_high - 1;
                cum = 0;
                // find next element which greater than heights[r_height] from
                // end to front
                while (cur > l_high && heights[cur] <= heights[r_high]) {
                    cum += heights[cur];
                    --cur;
                }
                // elements in (cur ... r_high) can safely calculate.
                rst += heights[r_high] * (r_high - cur - 1) - cum;
                r_high = cur;
            }
        }
        return rst;
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
        auto re = so.trapRainWater(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
