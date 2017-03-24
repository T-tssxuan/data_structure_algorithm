#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <map>
#include <random>
#include <unordered_set>
#include <set>
#include <bitset>
#include <numeric>

using namespace std;

using ll = long long;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[nums[0]];
        while (f != s) {
            f = nums[nums[f]];
            s = nums[s];
        }
        f = 0;
        while (f != s) {
            f = nums[f];
            s = nums[s];
        }
        return f;
    }
};

int main() {
    Solution so;
    vector<int> test = {1, 1, 2, 3, 4, 5};
    auto rst = so.findDuplicate(test);
    cout << rst << endl;
    return 0;
}
