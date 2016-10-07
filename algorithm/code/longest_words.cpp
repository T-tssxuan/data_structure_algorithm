#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/**
 * Describe: Given a series of words, find all words with the longest length.
 * Please provide a online algorithm.
 */

class Solution {
public:
    vector<string> longestWords(vector<string> &dictionary) {
        vector<int> indexes(dictionary.size(), 0);
        // building a flection for not moving words in the dictionary
        for (size_t i = 0; i < dictionary.size(); i++) {
            indexes[i] = i;
        }
        int pre = 0;
        int cur = 0;
        int idx1, idx2;
        for (size_t i = 1; i < dictionary.size(); i++) {
            idx1 = indexes[i];
            idx2 = indexes[cur];
            // split the array based on the current position
            if (dictionary[idx1].length() < dictionary[idx2].length()) {
                swap(indexes[i], indexes[pre]);
                pre++;
                cur++;
            } else if (dictionary[idx1].length() == dictionary[idx2].length()) {
                cur++;
            } else {
                cur = i;
                pre = i;
            }
        }
        vector<string> result;
        // retrieve all result
        while (dictionary.size() > 0 && pre <= cur) {
            result.push_back(dictionary[indexes[pre]]);
            pre++;
        }
        return result;
    }
};


int main() {
    Solution so;
    vector<string> test;
    int n;
    string str;
    while (cin >> n) {
        test.clear();
        while (n-- > 0) {
            cin >> str;
            test.push_back(str);
        }
        auto re = so.longestWords(test);
        cout << "result: ";
        for (auto& ele : re) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
