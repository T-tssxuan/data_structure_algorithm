#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
 * A implement of the KMP algorithm.
 * Provide four function:
 *  findFirst: find the first exist of pattern string in the source string.
 *  findAll: find all pattern string exist position in the source string.
 *  findFirstStartAt: find the first exist of pattern string in the source 
 *      string after the given position.
 *  findAllStartAt: find all pattern string exist position in the source string
 *      after the given position
 */

class KMP {
private:
    /**
     * The index table for the pattern stirng.
     * 0: init with -1.
     * 1: init with 1.
     * The rest is init with the pattern that backtrack to the common prefix
     * with the substring start at head.
     */
    vector<int> indexSearch(string &str) {
        vector<int> index(str.length(), -1);
        if (str.length() <= 2) {
            return index;
        }
        index[1] = 0;
        size_t pos = 2;
        size_t cur = 0;
        while (pos < str.length()) {
            if (str[pos - 1] == str[cur]) {
                index[pos] = cur + 1;
                ++cur;
                ++pos;
            } else if (cur > 0) {
                cur = index[cur];
                index[pos] = 0;
            } else {
                index[pos] = 0;
                ++pos;
            }
        }
        return index;
    }
public:
    int findFirst(string &s, string &p) {
        vector<int> index = indexSearch(p);
        int s_len = s.length();
        int p_len = p.length();
        int p_cur = 0;
        int s_cur = 0;
        while (s_cur < s_len) {
            if (p_cur == -1) {
                ++p_cur;
                ++s_cur;
            } else if (s[s_cur] == p[p_cur]) {
                if (p_cur == p_len - 1) {
                    return s_cur - p_cur;
                }
                ++p_cur;
                ++s_cur;
            } else {
                p_cur = index[p_cur];
            }
        }
        return -1;
    }
    vector<int> findAll(string &s, string &p) {
        vector<int> index = indexSearch(p);
        vector<int> result;
        int s_len = s.length();
        int p_len = p.length();
        int p_cur = 0;
        int s_cur = 0;
        while (s_cur < s_len) {
            if (p_cur == -1) {
                ++p_cur;
                ++s_cur;
            } else if (s[s_cur] == p[p_cur]) {
                if (p_cur == p_len - 1) {
                    result.push_back(s_cur - p_cur);
                    p_cur = index[p_cur];
                } else {
                    ++p_cur;
                    ++s_cur;
                }
            } else {
                p_cur = index[p_cur];
            }
        }
        return result;
    }
    int findFirstStartAt(string& s, int pos, string& p) {
        vector<int> index = indexSearch(p);
        int s_len = s.length();
        int p_len = p.length();
        int p_cur = pos;
        int s_cur = 0;
        while (s_cur < s_len) {
            if (p_cur == -1) {
                ++p_cur;
                ++s_cur;
            } else if (s[s_cur] == p[p_cur]) {
                if (p_cur == p_len - 1) {
                    return s_cur - p_cur;
                }
                ++p_cur;
                ++s_cur;
            } else {
                p_cur = index[p_cur];
            }
        }
        return -1;
    }
    vector<int> findAllStartAt(string& s, int pos, string& p) {
        vector<int> index = indexSearch(p);
        vector<int> result;
        int s_len = s.length();
        int p_len = p.length();
        int p_cur = pos;
        int s_cur = 0;
        while (s_cur < s_len) {
            if (p_cur == -1) {
                ++p_cur;
                ++s_cur;
            } else if (s[s_cur] == p[p_cur]) {
                if (p_cur == p_len - 1) {
                    result.push_back(s_cur - p_cur);
                    p_cur = index[p_cur];
                } else {
                    ++p_cur;
                    ++s_cur;
                }
            } else {
                p_cur = index[p_cur];
            }
        }
        return result;
    }
};

int main(int argc, char* argv[]) {
    KMP kmp;
    string s = "abcabcefgabcd";
    string p = "a";

    // test case findFirst
    cout << "findFirst: ";
    cout << kmp.findFirst(s, p) << endl;

    // test case findAll
    auto re = kmp.findAll(s, p);
    cout << "findAll: ";
    for (auto ele : re) {
        cout << ele << " ";
    }
    cout << endl;

    // test case findFirstStartAt
    cout << "findFirstStartAt: ";
    cout << kmp.findFirstStartAt(s, 2, p) << endl;

    // test case findAllStartAt
    cout << "findAllStartAt: ";
    re = kmp.findAllStartAt(s, 2, p);
    for (auto ele : re) {
        cout << ele << " ";
    }
    cout << endl;
    
    return 0;
}
