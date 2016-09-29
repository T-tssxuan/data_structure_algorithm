#include <iostream>
#include <vector>

using namespace std;

/**
 * The trie tree Node
 */
struct Node {
    struct Node* left;
    struct Node* right;
    int left_num; // The number of element less than
    int right_num; // The number of element greater than
    Node(int left_num, int right_num): left(nullptr), right(nullptr), \
                                       left_num(left_num), \
                                       right_num(right_num) {};
};

class Solution {
public:
    /**
     * The function get the number of pairs
     *
     * params:
     *  test: the number list
     *  m: the threshold
     */
    int getNum(vector<int>& test, int m) {
        Node* root = new Node(0, 0);

        // construct the trie tree
        for (auto& ele : test) {
            addNode(root, ele, 31);
        }

        long long result = 0;
        // accumulate the pair for each element
        for (auto& ele : test) {
            searchNode(root, ele, m, 31, result);
        }

        // each pairs calculate two times, get the half of it
        return result / 2;
    }

    /**
     * Search the trie tree to get the number
     * Conditions:
     *   1: m[pos] = 0, val[pos] = 0, so the right (1) side is ok (add to the 
     *      result), and continue the left (0) side of the node.
     *   2: m[pos] = 1, val[pos] = 0, so the left (0) side is invalid, and
     *      continue the right (1) side
     *   3: m[pos] = 0, val[pos] = 1, so the left (0) side is ok (add to the
     *      result), and continue the right (0) side.
     *   4: m[pos] = 1, val[pos] = 1, so the right (1) sid is invalid, and 
     *      continue the left (0) side.
     *
     * params:
     *  root: the root of the subtree
     *  val: current valid value
     *  pos: the bit pos [31....0]
     *  result: the accumulate result
     */
    void searchNode(Node* root, int val, int m, int pos, long long& result) {
        if (pos < 0 || !root) {
            return;
        }

        // get the bit value of m in "pos"
        int m_bit = (m & (1 << pos)) == 0? 0 : 1;
        // get the bit value of val in "pos"
        int val_bit = (val & (1 << pos)) == 0? 0 : 1;

        if (val_bit == 0) {
            if (m_bit == 0) {
                // condition 1
                result += root->right_num;
                searchNode(root->left, val, m, pos - 1, result);
            } else {
                // condition 2
                searchNode(root->right, val, m, pos - 1, result);
            }
        } else {
            if (m_bit == 0) {
                // condition 3
                result += root->left_num;
                searchNode(root->right, val, m, pos - 1, result);
            } else {
                // condition 4
                searchNode(root->left, val, m, pos - 1, result);
            }
        }
    }

    /**
     * Construct the trie tree
     *
     * params:
     *  root: the root of the subtree 
     *  val: the value need to insert to the trie tree
     *  pos: the bit pos [31....0]
     */
    void addNode(Node* root, int val, int pos) {
        if (pos < 0) {
            return;
        }

        // get the bit value of val in "pos"
        int tmp = (val & (1 << pos)) == 0? 0 : 1;

        if (tmp == 0) {
            // insert to the left and increase the count
            root->left_num++;
            if (!root->left) {
                root->left = new Node(0, 0);
            }
            addNode(root->left, val, pos - 1);
        } else {
            // insert to the right and increase the count
            root->right_num++;
            if (!root->right) {
                root->right = new Node(0, 0);
            }
            addNode(root->right, val, pos - 1);
        }
    }
};

int main() {
    Solution so;
    int n, m, tmp;
    vector<int> test;
    while (cin >> n) {
        // clear the previous input
        test.clear();
        cin >> m;
        while (n-- > 0) {
            cin >> tmp;
            test.push_back(tmp);
        }
        cout << so.getNum(test, m) << endl;
    }
    return 0;
}
