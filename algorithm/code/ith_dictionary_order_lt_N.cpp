#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    unsigned long long int getNumber(long long int n, long long int m) {
        vector<int> nums = getDigits(n);
        vector<long long int> counts;
        vector<int> digits(10, 0);
        long long int length = nums.size();
        long long int split;
        long long int left = m;
        long long int cur = 0;
        long long int sum = 0;
        long long int base = getBase(length - 2);
        for (int i = nums.size() - 2; i >= 0; i--) {
            sum += nums[i] * base + 1;
            base /= 10;
        }
        // cout << "sum: " << sum << endl;
        for (int i = 1; i < 10; i++) {
            if (i <= nums.back()) {
                digits[i] = length;
            } else {
                digits[i] = length - 1;
            }
        }
        for (int i = 1; i < 10; i++) {
            cur = i;
            if (left == 1) {
                return cur;
            }
            if (i == nums.back()) {
                if (left - sum - 1 <= 0) {
                    return recursiveTow(nums, cur, left - 1, digits[i] - 1);
                } else {
                    left = left - sum - 1;
                }
            } else {
                split = getTotal(digits[i] - 1) + 1;
                if (left - split <= 0) {
                    return recursive(left - 1, cur, digits[i] - 1);
                } else {
                    left -= split;
                }
            }
        }
        return 0;
    }
    long long int recursiveTow(vector<int>& nums, long long int cur, 
            long long int left, int unit_count) {
        long long int split = getTotal(unit_count - 1) + 1;
        // cout << "split tow: " << split << " cur: " << cur << " left: " << left \
        //      << " unit_count: " << unit_count << endl;
        for (int i = 0; i <= nums[unit_count - 1]; i++) {
            if (left == 1) {
                cur = cur * 10 + i;
                return cur;
            }
            if (i == nums[unit_count - 1]) {
                cur = cur * 10 + i;
                return recursiveTow(nums, cur, left - 1, unit_count - 1);
            } else {
                if (left - split <= 0) {
                    cur = cur * 10 + i;
                    return recursive(left - 1, cur, unit_count - 1);
                } else {
                    left -= split;
                }
            }
        }
        return 0;
    }
    // recursive counting the nubmer which less than the first nubmer
    long long int recursive(long long int left, long long int cur, int unit_count) {
        long long int split = getTotal(unit_count - 1) + 1;
        for (int i = 0; i <= 9; i++) {
            if (left == 1) {
                cur = cur * 10 + i;
                return cur;
            } else if (left - split <= 0) {
                cur = cur * 10 + i;
                return recursive(left - 1, cur, unit_count - 1);
            } else {
                left -= split;
            }
        }
        return 0;
    }
    long long int getBase(int unit_count) {
        long long int mul = 1;
        while (unit_count-- > 0) {
            mul *= 10;
        }
        return mul;
    }
    // git the total 
    long long int getTotal(int unit_count) {
        long long int sum = 0;
        long long int cur = 10;
        while (unit_count-- > 0) {
            sum += cur;
            cur *= 10;
        }
        return sum;
    }
    // Get all digitals of num
    vector<int> getDigits(long long int num) {
        vector<int> re;
        while (num > 0) {
            re.push_back(num % 10);
            num /= 10;
        }
        return re;
    }
};

int main() {
    Solution so;
    long long int n;
    long long int m;
    long long int re;
    while (cin >> n) {
        cin >> m;
        cout << "n: " << n << " m: " << m << endl;
        re = so.getNumber(n, m);
        cout << re << endl;
    }
    return 0;
}
