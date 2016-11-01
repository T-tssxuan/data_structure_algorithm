#include <cstring>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>


using namespace std;

bool compare(const string& str1, const string& str2) {
    size_t i = 0, j = 0;
    while (i < str1.size() && j < str2.size()) {
        if (str1[i] < str2[j]) {
            return true;
        } else if (str1[i] > str2[j]) {
            return false;
        }
        ++i;
        ++j;
    }
    if (i < str1.size()) {
        string left = str1.substr(0, i);
        string right = str1.substr(i);
        return compare(right, left);
    }
    if (j < str2.size()) {
        string left = str2.substr(0, i);
        string right = str2.substr(i);
        return compare(left, right);
    }
    return true;
};

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */
    using PQ = priority_queue<string, vector<string>, function<bool(string, string)>>;
    string largestNumber(vector<int> &num) {
        vector<string> strs(num.size());
        auto trans = [](int a) { return to_string(a); };
        transform(num.begin(), num.end(), strs.begin(), trans);
        PQ pq(strs.begin(), strs.end(), compare);
        string top;
        string rst;
        while (!pq.empty()) {
            top = pq.top();
            pq.pop();
            rst += top;
        }
        size_t pos = rst.find_first_not_of('0');
        if (pos == string::npos) {
            return "0";
        } else {
            return rst.substr(pos);
        }
    }
};

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
        string re = so.largestNumber(test);
        cout << "result: " << re << endl;
    }
    return 0;
}
