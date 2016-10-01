#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * Describe: Give a string 'str', shift the last k element to the first can 
 * make the shifted string equals the origin one. Calculate the minimal k.
 *
 * Solution: Check whether str[i * gap] (note: gap % str.length() = 0). If we 
 * get one, we need to check the rest element str[j + i * gap] (0 <= j < gap).
 * If all fulfill the condition, this gap is the result or increase gap by one
 * continue search.
 */

class Solution {
public:    
    int getStep(string str) {
        int len = str.size();
        int gap = 1;
        int idx;
        while (true) {
            // if len is not divided by gap, this gap is discarded
            while (len % gap != 0) {
                gap++;
            }
            // the length of gap must be less than len / 2
            if (gap > len / 2) {
                return len;
            }

            // scan the string compare the element with the gap
            char pre = str[len - gap];
            idx = len - 2 * gap;
            while (idx >= 0) {
                // if mismatch break
                if (pre != str[idx]) {
                    break;
                }
                idx -= gap;
            }

            // if scan with the gap success
            if (idx < 0) {
                if (gap == 1) {
                    return 1;
                }
                // compare the origin string and the shifted string
                int shift_idx = len - gap;
                int origin_idx = 0;
                bool state = true;
                for (int i = 0; i < len; i++) {
                    shift_idx = shift_idx % len;
                    if (str[origin_idx] == str[shift_idx]) {
                        shift_idx++;
                        origin_idx++;
                    } else {
                        state = false;
                        break;
                    }
                }
                // if the shifted string match the origin string, the gap is the
                // result
                if (state) {
                    return gap;
                }
            }
            // increase the gap by 'inc'
            gap++;
        }
        return len;
    }
};

int main() {
    Solution so;
    string str;
    while (cin >> str) {
        int re = so.getStep(str);
        cout << "result: " << re << endl << endl;
    }
    return 0;
}
