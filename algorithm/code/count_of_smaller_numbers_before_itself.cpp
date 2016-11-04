#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * The binary search tree node
     */
    struct Node {
        int count = 0; // number of element less than it
        int value; // it's value
        int equals = 1; // number of element equals to it
        struct Node *left = nullptr, *right = nullptr;
        Node(int value): value(value){}
    };
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> rst;
        Node *root = nullptr;
        for (auto ele : A) {
            // searching the result
            rst.push_back(searching(root, ele));

            // construct the binary searching tree
            if (!root) {
                root = new Node(ele);
            } else {
                insertNode(root, ele);
            }
        }
        return rst;
    }

    // insert new value into the binary searching tree
    void insertNode(Node *root, int value) {
        if (value == root->value) {
            root->equals++;
        } else if (value > root->value) {
            if (root->right) {
                insertNode(root->right, value);
            } else {
                root->right = new Node(value);
            }
        } else {
            root->count++;
            if (root->left) {
                insertNode(root->left, value);
            } else {
                root->left = new Node(value);
            }
        }
    }

    // searching the result in the binary searching tree
    int searching(Node *root, int value) {
        if (!root) {
            return 0;
        }
        if (value == root->value) {
            return root->count;
        } else if (value > root->value) {
            return searching(root->right, value) + root->equals + root->count;
        } else {
            return searching(root->left, value);
        }
    }
};


int main() {
    Solution so;
    vector<int> test;
    int n;
    while (cin >> n) {
        test = vector<int>(n);
        for (auto& ele : test) {
            cin >> ele;
        }
        auto re = so.countOfSmallerNumberII(test);
        cout << "result: ";
        for (auto ele : re) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
