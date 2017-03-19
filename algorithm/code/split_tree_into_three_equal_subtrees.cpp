#include <iostream>
#include <vector>

using namespace std;

/**
 * Describe: Given a tree, each node gets a value, you need to calculate the 
 * number of methods which split the tree into three subtrees, the split points 
 * should not be the root.
 *
 * Solution:
 *  a. Using dfs.
 *  b. Parent 2 * average should consider.
 *  c. Parent average should include after descendants visited.
 */

using ll = long long;

class Solution {
public:
    long long getCount(vector<ll> &values, vector<vector<int>> &childs, int root) {
        getSum(values, childs, root);
        if (values[root] % 3) {
            return 0;
        } else {
            int ss = 0;
            ll rst = 0;
            dfs(values, childs, root, values[root] / 3, rst, 0, ss, root);
            return rst;
        }
    }
    void dfs(vector<ll> &values, vector<vector<int>> &childs, int node, int av, 
            ll &rst, int dd, int &ss, int root) {
        if (values[node] == av) rst += ss + dd;
        if (node != root && values[node] == 2 * av)  dd++;
        for (auto ele : childs[node]) {
            dfs(values, childs, ele, av, rst, dd, ss, root);
        }
        if (values[node] == av) ss++;
    }
    int getSum(vector<ll> &values, vector<vector<int>> &childs, int node) {
        int sum = 0;
        for (auto c : childs[node]) {
            sum += getSum(values, childs, c);
        }
        values[node] += sum;
        return values[node];
    }
};

int main() {
    int T;
    cin >> T;
    Solution so;
    int root = 0;
    while (T-- > 0) {
        int n;
        cin >> n;
        vector<ll> values(n + 1, 0);
        vector<vector<int>> childs(n + 1);
        int v, p;
        for (int i = 1; i <= n; ++i) {
            cin >> v >> p;
            if (p == 0) {
                root = i;
            } else {
                childs[p].push_back(i);
            }
            values[i] = v;
        }
        int rst = so.getCount(values, childs, root);
        cout << rst << endl;
    }
    return 0;
}
