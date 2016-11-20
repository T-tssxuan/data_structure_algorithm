#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Describle: Given an array of illegal words, and a string, decide weather the
 * string contains any of illegal words.
 * Words is composed of a-z.
 */
class Solution {
public:
    // The trie tree node
    struct Node {
        bool tag = false; // indicate a complete word
        // the subtree pointer
        vector<struct Node*> next = vector<struct Node*>(26, nullptr);
        // indicate the source of the node
        //     True: from the trie tree
        //     False: from the trie network
        vector<bool> base = vector<bool>(26, false);
        // the traback position
        struct Node *missed_ptr;
    };
    vector<string> dic;
    Node *root = nullptr;
    Solution(vector<string> &dic) {
        this->dic.swap(dic);
        buildTrieTree();
        buildTrieGraph();
    }

    // valid the given article
    bool valid(string &article) {
        Node *cur = root;
        int idx;
        for (auto c : article) {
            idx = c - 'a';
            cur = cur->next[idx];
            if (cur->tag) {
                return true;
            }
        }
        return false;
    }

    void buildTrieGraph() {
        queue<Node*> node_q;
        node_q.push(root);
        root->missed_ptr = root;
        for (int i = 0; i < 26; ++i) {
            if (!root->next[i]) {
                root->next[i] = root;
            } else {
                root->next[i]->missed_ptr = root;
            }
        }
        // WFS scan the trie tree
        while (!node_q.empty()) {
            auto front = node_q.front();
            node_q.pop();
            for (int i = 0; i < 26; ++i) {
                if (front->base[i]) {
                    auto ptr = front->next[i];
                    for (int j = 0; j < 26; ++j) {
                        if (!ptr->next[j]) {
                            // build the reference for each missed path
                            ptr->next[j] = ptr->missed_ptr->next[j];
                        } else {
                            // get the track back node
                            ptr->next[j]->missed_ptr = ptr->missed_ptr->next[j];
                            // if the track back node is a word end, current 
                            // node also a word end
                            if (ptr->next[j]->missed_ptr->tag) {
                                ptr->next[j]->tag = true;
                            }
                        }
                    }
                    node_q.push(ptr);
                }
            }
        }
    }
    void buildTrieTree() {
        root = new Node();
        for (auto &str : dic) {
            insertWord(root, str, 0);
        }
    }
    void insertWord(Node *ptr, string& word, size_t pos) {
        if (pos == word.size()) {
            ptr->tag = true;
            return;
        }
        int idx = word[pos] - 'a';
        if (!ptr->next[idx]) {
            ptr->next[idx] = new Node();
            ptr->base[idx] = true;
        }
        insertWord(ptr->next[idx], word, pos + 1);
    }
};

/**
 * Input:
 *   n: the number of the illegal word.
 *   n line: n illegal word
 *   the validate string
 * Output: weather the string contains illegal words, if so print 'YES', or 'NO'
 *
 * Note: all string composed of a-z 
 */

int main() {
    int n;
    vector<string> dic;
    string article;
    cin >> n;
    dic = vector<string>(n);
    for (auto &str : dic) {
        cin >> str;
    }
    Solution so(dic);
    cin >> article;
    auto rst = so.valid(article);
    cout << (rst? "YES" : "NO") << endl;
    return 0;
}
