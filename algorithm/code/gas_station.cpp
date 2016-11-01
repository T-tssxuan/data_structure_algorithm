#include <vector>
#include <iostream>
using namespace std;

/**
 * Describe: Given a series of gas station and a series of cost, find a position
 * which start at can travel around the stations.
 *
 * Solution: Just like the max sum of subarray.
 */

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer 
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int len = gas.size();
        if (len < 1) {
            return 0;
        }

        // Get the distinct and the sum.
        int tmp = 0;
        for (int i = 0; i < len; ++i) {
            gas[i] = gas[i] - cost[i];
            tmp += gas[i];
        }

        // If sum of the sequence less than zero, it is impossible
        if (tmp < 0) {
            return -1;
        }

        // If sum of [a...b](num[a] >= 0) less than zeros, then every position
        // between [a...b] will fail also.
        int start = 0;
        int sum = 0;
        for (int i = 0; i < len; ++i) {
            sum += gas[i];
            if (sum < 0) {
                start = i + 1;
                sum = 0;
            }
        }
        return start;
    }
};

/**
 * Input:
 *  n
 *  gas1 gas2 gas3 ...
 *  cost1 cost2 cost3 ...
 */

int main() {
    Solution so;
    vector<int> gas;
    vector<int> cost;
    int n;
    while (cin >> n) {
        gas = vector<int>(n);
        cost = vector<int>(n);
        for (int i = 0; i < n; i++) {
            cin >> gas[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> cost[i];
        }
        int re = so.canCompleteCircuit(gas, cost);
        cout << "result: " << re << endl;
    }
    return 0;
}
