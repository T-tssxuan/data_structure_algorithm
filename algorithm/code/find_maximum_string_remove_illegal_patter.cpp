#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Descirbe: Find the minimal delete in the given string.
 * Note: Based on the previous max length characters.
 */

class Solution{
public:
    int getMaxValidString(string& str, vector<vector<bool>>& table) {
        if (str.empty()){
            return 0;
        }
        vector<int> record(26, 0);
        int tmp = 0;
        for (auto c : str) {
            tmp = 0;
            for (int i = 0; i < 26; i++) {
                if (!table[i][c - 'a']) {
                    tmp = tmp > record[i]? tmp : record[i];
                }
            }
            if (tmp + 1 > record[c - 'a']) {
                record[c - 'a'] = tmp + 1;
            }
        }
        return str.size() - *max_element(record.begin(), record.end());
    }
};

int main() {
    Solution so;
    int n, m;
    string str;
    string tmp;
    vector<vector<bool>> table;
    while (cin >> n) {
        cin >> str;
        cin >> m;
        table = vector<vector<bool>>(26, vector<bool>(26, false));
        while (m-- > 0) {
            cin >> tmp;
            table[tmp[0] - 'a'][tmp[1] - 'a'] = true;
            table[tmp[1] - 'a'][tmp[0] - 'a'] = true;
        }
        int re = so.getMaxValidString(str, table);
        cout << re << endl;
    }
    return 0;
}
