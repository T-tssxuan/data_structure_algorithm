#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <map>

using namespace std;
/**
 * Deep first travel.
 * Subtrees' travel sequence form the root tree's sequence.
 * A sequence of a tree must adjacent.
 */

bool cmp(vector<int> &vec1, vector<int> &vec2) {
    return vec1[0] < vec2[0];
}

class Solution {
public:
    bool isValid(vector<vector<bool>> &matrix, vector<int> &sequence) {
        int n = matrix.size();
        vector<bool> visited(n, false);
        map<int, int> idx;
        for (size_t i = 0; i < sequence.size(); ++i) {
            idx[sequence[i]] = i;
        }
        bool valid = true;
        dfs(matrix, visited, 1, idx, valid);
        return valid;
    }
    vector<int> dfs(vector<vector<bool>> &matrix, vector<bool> &visited, 
            int city, map<int, int> &idx, bool &valid) {
        vector<int> rst;
        if (idx.find(city) != idx.end()) {
            rst.push_back(idx[city]);
        }
        visited[city] = true;
        vector<vector<int>> tmp;
        for (size_t i = 1; i < matrix.size(); ++i) {
            if (!visited[i] && matrix[city][i]) {
                auto ele = dfs(matrix, visited, i, idx, valid);
                if (!valid) {
                    return vector<int>();
                }
                if (!ele.empty()) {
                    tmp.push_back(ele);
                }
            }
        }
        sort(tmp.begin(), tmp.end(), cmp);
        for (size_t i = 0; i < tmp.size(); ++i) {
            rst.insert(rst.end(), tmp[i].begin(), tmp[i].end());
        }
        if (rst.size() > 0 && rst.back() - rst.front() + 1 != rst.size()) {
            valid = false;
        }
        return rst;
    }
    bool ancestorContainAfter(int pos, vector<bool> &ancestor, vector<int> &sequence) {
        for (size_t i = pos + 1; i < sequence.size(); ++i) {
            if (ancestor[sequence[i]]) {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    Solution so;
    int num;
    int x, y;
    cin >> num;
    int citys;
    int seqNum;
    while (num-- > 0) {
        cin >> citys;
        vector<vector<bool>> matrix(citys + 1, vector<bool>(citys + 1, false));
        while (citys-- > 1) {
            cin >> x >> y;
            matrix[x][y] = true;
            matrix[y][x] = true;
        }
        cin >> seqNum;
        vector<int> sequence;
        int tmp;
        while (seqNum-- > 0) {
            cin >> tmp;
            sequence.push_back(tmp);
        }
        bool rst = so.isValid(matrix, sequence);
        if (rst) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}

