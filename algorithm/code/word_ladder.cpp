#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

/**
 * Describe: 
 * Given two words (start and end), and a dictionary, find the length of 
 * shortest transformation sequence from start to end, such that:
 * 1. Only one letter can be changed at a time
 * 2. Each intermediate word must exist in the dictionary
 *
 * Source: lintcode http://www.lintcode.com/en/problem/word-ladder/
 *
 * Solution: Regard it as a graph, so each step is the transfer between the
 * two neighbors. Each word can have 25 * str.length() beighbors at most.
 */

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            return 1;
        }
        dict.erase(start);
        // level scan record, each level increase one
        queue<pair<string, int>> record;
        record.push(make_pair(start, 1));
        pair<string, int> tmp;
        string cur;
        while (!record.empty()) {
            tmp = record.front();
            record.pop();
            // scan all neighbor
            for (size_t i = 0; i < start.length(); i++) {
                cur = tmp.first;
                for (int j = 0; j < 26; j++) {
                    cur[i] = 'a' + j;
                    if (cur == end) {
                        return tmp.second + 1;
                    }
                    if (dict.find(cur) != dict.end()) {
                        record.push(make_pair(cur, tmp.second + 1));
                        // remove the node if existed
                        dict.erase(cur);
                    }
                }
            }
        }
        return -1;
    }
};

/**
 * Input: first line: the start and end string
 *        second line: a number n followed n string
 * Output: the minimal depth
 */

int main() {
    Solution so;
    string str1;
    string str2;
    string tmp;
    unordered_set<string> test;
    int num;
    while (cin >> str1) {
        test.clear();
        cin >> str2;
        cin >> num;
        while (num-- > 0) {
            cin >> tmp;
            test.insert(tmp);
        }
        int result = so.ladderLength(str1, str2, test);
        cout << result << endl;
    }
    return 0;
}
