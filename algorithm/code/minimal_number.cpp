#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * Describe: Give a series of number, find the minimal number they can find.
 */

// The order decide compare
bool compare(const string &str1, const string &str2){
    size_t idx1 = 0;
    size_t idx2 = 0;
    while (idx1 < str1.length() && idx2 < str2.length()) {
        if (str1[idx1] > str2[idx2]) {
            return true;
        } else if (str1[idx1] < str2[idx2]) {
            return false;
        }
        ++idx1;
        ++idx2;
    }
    if (idx1 < str1.length()) {
        string tmp = str1.substr(idx1);
        return compare(tmp, str2);
    }
    if (idx2 < str2.length()) {
        string tmp = str2.substr(idx2);
        return compare(str1, tmp);
    }
    return false;
};

class Solution {
public:
    using PQ = priority_queue<string, vector<string>, function<bool(const string &, const string &)>>;
    string minNumber(vector<int>& nums) {
        vector<string> strs(nums.size());
        auto trans = [](int a){ return to_string(a); };
        transform(nums.begin(), nums.end(), strs.begin(), trans);
        PQ pq(strs.begin(), strs.end(), compare);
        string rst;
        while (!pq.empty()) {
            rst += pq.top();
            pq.pop();
        }
        size_t idx = 0;
        while (idx < rst.length() && rst[idx] == '0') {
            ++idx;
        }
        rst = rst.substr(idx);
        return rst == ""? "0" : rst;
    }
};

int main() {
    Solution so;
    int n;
    vector<int> test;
    while (cin >> n) {
        test = vector<int>(n);
        for (auto& ele : test) {
            cin >> ele;
        }
        auto re = so.minNumber(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
