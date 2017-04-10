#include <iostream>
#include <vector>

using namespace std;

class Floyd {
public:
    void solve(vector<vector<int>> &grpah) {
        int len = grpah.size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                for (int k = 0; k < len; ++k) {
                    if (grpah[i][j] < grpah[i][k] + grpah[k][j]) {
                        grpah[i][j] = grpah[i][k] + grpah[k][j];
                    }
                }
            }
        }
    }
};
