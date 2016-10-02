#include <iostream>
#include <vector>

using namespace std;

/**
 * Solution: Using an array to record the position i in string S, with 
 * correspond position j in T with S[i] = T[j], and set the position i in array
 * (i, count), the 'count' is the accumulate the y of the element (x, y) which
 * with x = i - 1 and position previous i.
 */

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        if (T.size() == 0) {
            return 1;
        }
        if (S.size() == 0) {
            return 0;
        }
        vector<pair<int, int>> record(S.size(), make_pair(-1, 0));
        // initial the array
        for (size_t i = 0; i < record.size(); i++) {
            if (S[i] == T[0]) {
                record[i].first = 0;
                record[i].second = 1;
            }
        }
        pair<int, int> tmp;
        int prefix_count;
        int idx;
        for (size_t i = 1; i < T.size(); i++) {
            prefix_count = 0;
            idx = i - 1;
            for (size_t j = 0; j < S.size(); j++) {
                tmp = record[j];
                if (T[i] == S[j]) {
                    record[j].first = i;
                    record[j].second = prefix_count;
                }
                if (tmp.first == idx) {
                    prefix_count += tmp.second;
                }
            }
        }
        int re = 0;
        for (size_t i = 0; i < record.size(); i++) {
            if (record[i].first == static_cast<int>(T.size() - 1)) {
                re += record[i].second;
            }
        }
        return re;
    }
};

/**
 * Input: tow string need to calculate the result
 * Output: the result
 */
int main() {
    Solution so;
    string str1;
    string str2;
    while (cin >> str1) {
        cin >> str2;
        cout << str1 << " " << str2 << endl;
        int result = so.numDistinct(str1, str2);
        cout << "result: " << result << endl;
    }
    return 0;
}
