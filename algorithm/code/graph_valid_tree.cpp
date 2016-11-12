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
     * @param n an integer
     * @param edges a list of undirected edges
     * @return true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n == 0 || n == 1) {
            return true;
        }
        if (edges.size() == 0 && n > 0) {
            return false;
        }
        vector<int> record(n, 0);
        for (int i = 0; i < n; ++i) {
            record[i] = i;
        }
        int min, max;
        for (auto& edge : edges) {
            if (record[edge[0]] != record[edge[1]]) {
                min = record[edge[0]] < record[edge[1]]? \
                      record[edge[0]] : record[edge[1]];
                max = record[edge[0]] > record[edge[1]]? \
                      record[edge[0]] : record[edge[1]];
                for (int i = 0; i < n; ++i) {
                    if (record[i] == max) {
                        record[i] = min;
                    }
                }
            } else {
                return false;
            }
        }
        for (auto ele : record) {
            if (ele != 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}
