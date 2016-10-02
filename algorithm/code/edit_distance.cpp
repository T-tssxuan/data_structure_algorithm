#include <iostream>
#include <vector>

using namespace std;

/**
 * Describe: Given two string str1, str2, calculate the distance between str1 
 * and str2. The distance increase by one when do either operation of the 
 * Insert, Delete, Replace.
 */

class Solution {
public:    
    int minDistance(string word1, string word2) {
        if (word1 == word2) {
            return 0;
        }
        // word_long: the longer string, word_short: the shorter one
        string word_long = word1.size() > word2.size()? word1 : word2;
        string word_short = word1.size() > word2.size()? word2 : word1;
        vector<int> record(word_long.size(), 0);
        int tmp_min;
        int min = 0;
        int tmp;
        for (size_t i = 0; i < word_short.size(); i++) {
            // the cost to insert i element, which will result i delete cost
            // so it is i * 2
            tmp_min = i * 2;
            for (size_t j = 0; j < word_long.size(); j++) {
                tmp = record[j];
                record[j] = word_long[j] == word_short[i]? \
                            tmp_min : tmp_min + 1;
                // insert a element cost will 2 more based current
                record[j] = record[j] < tmp + 2? record[j] : tmp + 2;
                // the minimal cost for i - 1 in previous position
                tmp_min = tmp_min < tmp? tmp_min : tmp;
            }
        }

        // get the minimal cost
        min = record[0];
        for (auto ele : record) {
            min = min < ele? min : ele;
        }
        return min + word_long.size() - word_short.size();
    }
};

int main() {
    Solution so;
    string str1;
    string str2;
    while (cin >> str1) {
        cin >> str2;
        int re = so.minDistance(str1, str2);
        cout << "result: " << re << endl << endl;
    }
    return 0;
}
