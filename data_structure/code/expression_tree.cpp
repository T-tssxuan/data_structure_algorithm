#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
        this->symbol = symbol;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    ExpressionTreeNode* build(vector<string> &expression) {
        stack<ExpressionTreeNode*> numbers;
        stack<ExpressionTreeNode*> ops;
        for (auto ele : expression) {
            cout << ele << endl;
            if (ele == "(") {
                ops.push(new ExpressionTreeNode(ele));
            } else if (ele == ")") {
                while (ops.top()->symbol != "(") {
                    merge(numbers, ops);
                }
                ops.pop();
            } else if (ele == "+" || ele == "-") {
                while (!ops.empty() && ops.top()->symbol != "(") {
                    merge(numbers, ops);
                }
                ops.push(new ExpressionTreeNode(ele));
            } else if (ele == "*" || ele == "/") {
                if (!ops.empty()) {
                    if (ops.top()->symbol == "/" || ops.top()->symbol == "*") {
                        merge(numbers, ops);
                    }
                }
                ops.push(new ExpressionTreeNode(ele));
            } else {
                numbers.push(new ExpressionTreeNode(ele));
            }
        }
        while (!ops.empty()) {
            merge(numbers, ops);
        }
        if (numbers.empty()) { 
            return nullptr;
        }
        return numbers.top();
    }
    void merge(stack<ExpressionTreeNode*> &numbers, 
            stack<ExpressionTreeNode*> &ops) {
        if (ops.empty()) {
            return;
        }
        if (ops.top()->symbol == "(") {
            return;
        }

        ExpressionTreeNode *op_top;
        ExpressionTreeNode *number_top1;
        ExpressionTreeNode *number_top2;

        op_top = ops.top();
        ops.pop();

        number_top1 = numbers.top();
        numbers.pop();
        number_top2 = numbers.top();
        numbers.pop();

        op_top->right = number_top1;
        op_top->left = number_top2;

        numbers.push(op_top);
    }
};

int main() {
    Solution so;
    vector<string> test{"2", "+", "3", "(", "5", "+", "(", "6", "*", "7", ")", ")"};
    so.build(test);
    return 0;
}
