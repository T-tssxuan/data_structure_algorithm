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
class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        size_t point = n.find_first_of('.');
        string integer = "";
        string fraction = "";
        if (point == string::npos) {
            integer = n;
        } else {
            integer = n.substr(0, point);
            fraction = n.substr(point + 1);
        }
        string rst = getIntegerToBinary(integer);
        fraction = getFractionToBinary(fraction);
        if (fraction == "ERROR") {
            return "ERROR";
        }
        if (fraction != "") {
            rst.push_back('.');
            rst.insert(rst.end(), fraction.begin(), fraction.end());
        }
        return rst;
    }
    string getIntegerToBinary(string& str) {
        int num = stoi(str);
        string re = "";
        int remainder = 0;
        while (num > 0) {
            remainder = num % 2;
            num /= 2;
            if (remainder == 0) {
                re.push_back('0');
            } else {
                re.push_back('1');
            }
        }
        reverse(re.begin(), re.end());
        if (re == "") {
            re = "0";
        }
        return re;
    }
    string getFractionToBinary(string str) {
        reverse(str.begin(), str.end());
        string rst = "";
        int idx = 0;
        while (idx < 32 && str != "") {
            int carry = getStringMultiTwo(str);
            rst.push_back(carry + '0');
            idx++;
        }
        if (idx == 32 && str != "") {
            return "ERROR";
        }
        if (rst == "0") {
            rst = "";
        }
        return rst;
    }
    int getStringMultiTwo(string& str) {
        int carry = 0;
        int num = 0;
        int tmp = 0;
        string rst = "";
        for (size_t i = 0; i < str.length(); ++i) {
            num = (str[i] - '0') * 2 + carry;
            tmp = num % 10;
            rst.push_back(tmp + '0');
            carry = num / 10;
        }
        size_t pos = rst.find_first_not_of('0');
        if (pos == string::npos) {
            str = "";
        } else {
            str = rst.substr(pos);
        }
        return carry;
    }
};


int main() {
    Solution so;
    vector<int> test;
    string str;
    while (cin >> str) {
        string re = so.binaryRepresentation(str);
        cout << "result: " << re << endl;
    }
    return 0;
}
