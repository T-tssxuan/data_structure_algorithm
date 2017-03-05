#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool judge(vector<pair<int, int>> &points) {
        map<pair<int, int>, bool> foo;
        for (auto ele : points) {
            if (foo.find(ele) == foo.end()) {
                foo[ele] = true;
            }
        }
        if (foo.size() != 4) {
            return false;
        }
        vector<pair<int, int>> vecs;
        for (int i = 0; i < 8; i += 2) {
            auto tmp = getVec(points[i], points[i + 1]);
            if (tmp.first == 0 && tmp.second == 0) {
                return false;
            }
            vecs.push_back(tmp);
        }
        if (vecs[0] == vecs[1]) {
            if (vecs[2] == vecs[3]) {
                return vecs[0].first * vecs[2].first + vecs[0].second * vecs[2].second == 0;
            }
            return false;
        }
        if (vecs[0] == vecs[2]) {
            if (vecs[1] == vecs[3]) {
                return vecs[0].first * vecs[1].first + vecs[0].second * vecs[1].second == 0;
            }
            return false;
        }
        if (vecs[0] == vecs[3]) {
            if (vecs[1] == vecs[2]) {
                return vecs[0].first * vecs[1].first + vecs[0].second * vecs[1].second == 0;
            }
            return false;
        }
        return false;
    }
    pair<int, int> getVec(pair<int, int> p1, pair<int, int> p2) {
        if (p1.first < p2.first) {
            return make_pair(p2.first - p1.first, p2.second - p1.second);
        }
        if (p1.first > p2.first) {
            return make_pair(p1.first - p2.first, p1.second - p2.second);
        }
        if (p1.second < p2.second) {
            return make_pair(p2.first - p1.first, p2.second - p1.second);
        } else {
            return make_pair(p1.first - p2.first, p1.second - p2.second);
        }
    }
};

int main(int argc, char *argv[]) {
    Solution so;
    int num;
    int x, y;
    vector<pair<int, int>> points;
    cin >> num;
    while (num-- > 0) {
        points.clear();
        for (int i = 0; i < 8; ++i) {
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }
        bool rst = so.judge(points);
        if (rst) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

