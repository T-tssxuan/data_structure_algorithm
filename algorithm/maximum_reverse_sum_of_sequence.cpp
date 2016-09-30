#include <iostream>
#include <vector>

using namespace std;

/** Describe
 * Given a series of numbers, we can reverse the suffix, prefix or both. Get the
 * maximum subarray sum of the numbers.
 * 
 * note: reverse must beginning at the first one or the last one.
 * such as: 2 2 3 4 -2 -3 can transform to: -2 -2 3 4 -2 3
 */

class Solution{
public:
    int getMax(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        // recorder the maximum sequence start from idx
        vector<int> max_forward(nums.size(), 0);
        vector<int> max_backward(nums.size(), 0);
        // recorder the prefix sum of the origin sequence
        vector<int> sum(nums.size(), 0);
        int tmp = 0;
        int len = nums.size();
        int cur_max = nums[0];
        int max = nums[0];

        // calculate the forward suffix max sequence
        for (int i = 0; i < len; i++) {
            tmp -= nums[i];
            cur_max = cur_max > tmp? cur_max : tmp;
            tmp = tmp > 0? tmp : 0;
            max_forward[i] = tmp;
        }
        max = max > cur_max? max : cur_max;

        tmp = 0;
        cur_max = 0;
        // calculate the backword prefix max sequence
        for (int i = len - 1; i >= 0; i--) {
            tmp -= nums[i];
            cur_max = cur_max > tmp? cur_max : tmp;
            tmp = tmp > 0? tmp : 0;
            max_backward[i] = tmp;
        }
        max = max > cur_max? max : cur_max;
        tmp = 0;
        for (int i = 0; i < len; i++) {
            tmp += nums[i];
            sum[i] = tmp;
        }
        int pre = 0;
        int mid = 0;
        int suf = 0;
        int cur;
        // get the maximum value from the composition:
        // [reversed suffix maximum sum] + [orgin sequence] + [reversed prefix
        // maximum sum]
        for (int i = -1; i < len; i++) {
            for (int j = i + 1; j <= len; j++) {
                pre = i == -1? 0 : max_forward[i];
                suf = j == len? 0 : max_backward[j];
                mid = sum[j - 1] - sum[i];
                cur = pre + suf + mid;
                max = max > cur? max : cur;
            }
        }
        return max;
    }
};


/**
 * Input: n the number of elements followed by n elements
 * Output: the maximum sum
 */
int main() {
    Solution so;
    int n;
    vector<int> test;
    int tmp;
    while (cin >> n) {
        test.clear();
        while (n-- > 0) {
            cin >> tmp;
            test.push_back(tmp);
        }
        cout << so.getMax(test) << endl;
    }
    return 0;
}
