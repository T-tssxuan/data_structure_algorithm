#include <iostream>
#include <vector>
#include <map>

using namespace std;

/**
 * Describe: Given a list, the value V(l, r) is the number of pairs in range 
 * l...r, please calculate the the ith value in all V(l, r).
 * Source: http://hihocoder.com/problemset/problem/1483
 *
 * Solution:
 *  1. Using the double pointer
 *  2. Using binary search
 *  3. How to accumulate the number of count.
 */

using ll = long long;

class Solution {
public:
    bool check(vector<ll> &a, ll count, ll x, ll k) {
        vector<ll> nums(count, 0);
        ll len = a.size();
        ll cum = 0;
        ll l = 0;
        ll kk = 0;
        // Using the double pointer to accumulate the value which 
        // less x
        for (ll i = 0; i < len; ++i) {
            cum += nums[a[i]]++;
            while (cum > x) {
                cum -= --nums[a[l++]];
            }
            kk += i - l + 1;
        }
        return kk >= k;
    }
    ll getResult(vector<ll> &src, ll k) {
        map<ll, ll> m;
        ll len = src.size();
        vector<ll> a(src.size());
        ll count = 0;
        for (ll i = 0; i < len; ++i) {
            if (m.find(src[i]) == m.end()) m[src[i]] = count++;
            a[i] = m[src[i]];
        }
        ll l = 0, r = (len - 1) * len / 2;
        ll mid;
        // binary search
        while (l <= r) {
            mid = (l + r) >> 1;
            if (check(a, count, mid, k)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    ll cases;
    cin >> cases;
    ll n, k;
    Solution so;
    while (cases--) {
        cin >> n >> k;
        vector<ll> nums(n);
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
        }
        ll rst = so.getResult(nums, k);
        cout << rst << endl;
    }
}
