#include <iostream>
#include <string>
#include <vector>
#include <istream>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <sstream>

using namespace std;
using ll = long long;
struct Point {
    ll x;
    ll y;
};

ll MAX_VAL = 100000000;
int main() {
    int n;
    cin >> n;
    pair<ll, ll> lt, rb;
    cin >> lt.first >> lt.second >> rb.first >> rb.second;
    if (n == 1) {
        cout << lt.first << " " << lt.second << " " << rb.first << " " << rb.second << endl;
        return 0;
    }
    map<pair<ll, ll>, int> mm;
    vector<ll> xx;
    vector<ll> yy;
    pair<ll, ll> plt, prb;
    for (int i = 0; i < n - 1; ++i) {
        cin >> plt.first >> plt.second >> prb.first >> prb.second;
        xx.push_back(plt.first);
        xx.push_back(prb.first);
        yy.push_back(plt.second);
        yy.push_back(prb.second);
        if (mm.find(make_pair(plt.first, plt.second)) == mm.end()) {
            mm[make_pair(plt.first, plt.second)] = 0;
        }
        mm[make_pair(plt.first, plt.second)] += 1;
        if (mm.find(make_pair(plt.first, prb.second)) == mm.end()) {
            mm[make_pair(plt.first, prb.second)] = 0;
        }
        mm[make_pair(plt.first, prb.second)] += 1;
        if (mm.find(make_pair(prb.first, prb.second)) == mm.end()) {
            mm[make_pair(prb.first, prb.second)] = 0;
        }
        mm[make_pair(prb.first, prb.second)] += 1;
        if (mm.find(make_pair(prb.first, plt.second)) == mm.end()) {
            mm[make_pair(prb.first, plt.second)] = 0;
        }
        mm[make_pair(prb.first, plt.second)] += 1;
    }
    vector<pair<ll, ll>> candidate;
    for (auto ele : mm) {
        if ((ele.first.first == lt.first || ele.first.first == rb.first) &&
                (ele.first.second == lt.second || ele.first.second == rb.second)) {
            continue;
        } else {
            if (ele.second % 2 == 1) {
                candidate.push_back(ele.first);
            }
        }
    }
    int idx = 0;;
    pair<ll, ll> rlt, rrb;
    if (candidate.size() == 2) {
        if (candidate[0].first == candidate[1].first) {
            while (candidate[0].first == xx[idx]) { ++idx; }
            if (candidate[0].first > xx[idx]) {
                rlt.first = candidate[0].first;
                rlt.second = lt.second;
                rrb = rb;
            } else {
                rlt = lt;
                rrb.first = candidate[0].first;
                rrb.second = rb.second;
            }
        } else {
            while (candidate[0].second == yy[idx]) { ++idx; }
            if (candidate[0].second > yy[idx]) {
                rlt.first = lt.first;
                rlt.second = candidate[0].second;
                rrb = rb;
            } else {
                rlt = lt;
                rrb.first = rb.first;
                rrb.second = candidate[0].second;
            }
        }
    } else {
        rlt = rb;
        rrb = lt;
        for (auto ele : candidate) {
            rlt.first = min(rlt.first, ele.first);
            rlt.second = min(rlt.second, ele.second);
            rrb.first = max(rrb.first, ele.first);
            rrb.second = max(rrb.second, ele.second);
        }
    }
    cout << rlt.first << " " << rlt.second << " " << rrb.first << " " << rrb.second << endl;
    return 0;
}
