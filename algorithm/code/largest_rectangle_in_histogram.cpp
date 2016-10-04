#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/**
 * Describe: Given n non-negative integers representing the histogram's bar height
 * where the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 */

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleArea(vector<int> &height) {
        stack<pair<int, int>> record;
        int max = 0;
        int tmp;
        int start = 0;
        for (size_t i = 0; i < height.size(); i++) {
            start = i;
            // find the beginning position for the new element
            // find the ending position for the element already in the stack
            while (!record.empty() && record.top().second > height[i]) {
                // set the beginning position with a lower value
                start = record.top().first;
                // calculate the ending of the element int the stact and
                // get it's area
                tmp = (i - record.top().first) * record.top().second;
                max = max > tmp? max : tmp;
                record.pop();
            }
            record.push(make_pair(start, height[i]));
        }
        // pop all element in the stack and get the value
        while (!record.empty()) {
            tmp = (height.size() - record.top().first) * record.top().second;
            max = max > tmp? max : tmp;
            record.pop();
        }
        return max;
    }
};

/**
 * Input: a number 'n' followed by n height of the bars
 * Output: the max area
 */
int main() {
    Solution so;
    vector<int> test;
    int n;
    int tmp;
    while (cin >> n) {
        test.clear();
        while (n-- > 0) {
            cin >> tmp;
            test.push_back(tmp);
        }
        int re = so.largestRectangleArea(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
