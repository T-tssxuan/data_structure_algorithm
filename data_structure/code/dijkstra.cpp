#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Dijkstra {
public:
    vector<int> solve(vector<vector<int>> &graph, int src) {
        int len = graph.size();
        vector<int> rst = graph[src];
        vector<bool> visited(len, false);
        visited[src] = true;
        int count = len - 1;
        int idx;
        int tmp_min;
        while (count-- > 0) {
            tmp_min = -1;
            for (int i = 0; i < len; ++i) {
                if (!visited[i] && rst[i] != -1 && (tmp_min == -1 || rst[i] < tmp_min)) {
                    idx = i;
                    tmp_min = rst[i];
                }
            }
            visited[idx] = true;
            for (int i = 0; i < len; ++i) {
                if (!visited[i] && graph[idx][i] != -1 && 
                        (rst[i] == -1 || graph[idx][i] + rst[idx] < rst[i])) {
                    rst[i] = graph[idx][i] + rst[idx];
                }
            }
        }
        return rst;
    }
};

