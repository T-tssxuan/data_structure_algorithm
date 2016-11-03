#include <iostream>
#include <vector>
using namespace std;

/**
 * Describe: This is a sample of segment tree, except of the start and end
 * position each node includes the minimal value of its range.
 */

class SegmentTree { 
public:
    struct Node {
        int start;
        int end;
        int min;
        struct Node *left = nullptr;
        struct Node *right = nullptr;
        Node(int start, int end): start(start), end(end){}
    };

    /**
     * Search a range of the tree.
     * Params:
     *  root: the root of the segment tree
     *  start: start of the searching range
     *  end: end of the searching range
     * return:
     *  The minimal value of the given range.
     */
    int getMin(Node *root, int start, int end) {
        if (root->start == start && root->end == end) {
            return root->min;
        }
        int mid = (root->start + root->end) / 2;
        if (end <= mid) {
            return getMin(root->left, start, end);
        } else if (start > mid) {
            return getMin(root->right, start, end);
        } else {
            int left = getMin(root->left, start, mid);
            int right = getMin(root->right, mid + 1, end);
            return left < right? left : right;
        }
    }

    /**
     * A segment tree is built from a range of array.
     * Params:
     *  A: a vector contains the information
     *  start: the start index of the range which is used to building segment
     *         tree.
     *  end: the end index of the range.
     * return:
     *  The root of the segment tree.
     */
    Node* buildSegmentTree(vector<int>& A, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        Node *root = new Node(start, end);
        if (start == end) {
            root->min = A[start];
        } else {
            int mid = (start + end) / 2;
            root->left = buildSegmentTree(A, start, mid);
            root->right = buildSegmentTree(A, mid + 1, end);
            root->min = root->left->min < root->right->min? \
                        root->left->min : root->right->min;
        }
        return root;
    }

    void modify(Node* root, int index, int value) {
        if (index < root->start || index > root->end) {
            return;
        }
        if (index == root->start && index == root->end) {
            root->min = value;
            return;
        }
        int mid = (root->start + root->end) / 2;
        if (index <= mid) {
            modify(root->left, index, value);
        } else {
            modify(root->right, index, value);
        }
        root->min = root->left->min < root->right->min? \
                    root->left->min : root->right->min;
    }
};


int main() {
    SegmentTree st;
    vector<int> test {1, 3, 4, 2, 4, 5, 9, 1};
    SegmentTree::Node *root = st.buildSegmentTree(test, 0, test.size() - 1);
    int re = st.getMin(root, 0, 3);
    cout << "result: " << re << endl;

    st.modify(root, 2, -1);
    re = st.getMin(root, 0, 3);
    cout << "result: " << re << endl;

    return 0;
}
