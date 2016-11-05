#include <string>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Describe: Given an expression string array, return the Reverse Polish 
 * notation of this expression. (remove the parentheses)
 *
 * Solution: 
 *  a. encounter ')' need reduce to next '(' in op stack
 *  b. encounter '+' or '-' need to reduce all op in the stack or encounter '('
 *  c. encounter '/' or '*' need to reduce all consecutive '*' or '/' in the
 *     stack.
 *  d. expression_a op expression_b
 *     ==> [convert(expression_a), expression_b, op]
 */

class Solution {
public:
    vector<string> convertToRPN(vector<string> &expression) {
        stack<vector<string>> numbers;
        stack<string> ops;
        for (auto ele : expression) {
            if (ele == "(") {
                ops.push(ele);
            } else if (ele == ")") {
                while (ops.top() != "(") {
                    merge(numbers, ops);
                }
                ops.pop();
            } else if (ele == "+" || ele == "-") {
                while (!ops.empty() && ops.top() != "(") {
                    merge(numbers, ops);
                }
                ops.push(ele);
            } else if (ele == "*" || ele == "/") {
                if (!ops.empty()) {
                    if (ops.top() == "/" || ops.top() == "*") {
                        merge(numbers, ops);
                    }
                }
                ops.push(ele);
            } else {
                numbers.push(vector<string>{ele});
            }
        }
        while (!ops.empty()) {
            merge(numbers, ops);
        }
        if (!numbers.empty()) {
            return numbers.top();
        }
        return vector<string>();
    }
    void merge(stack<vector<string>> &numbers, stack<string> &ops) {
        if (ops.empty()) {
            return;
        }
        if (ops.top() == "(") {
            return;
        }

        string op_top = ops.top();
        ops.pop();

        vector<string> &numbers_top = numbers.top();
        numbers.pop();
        numbers_top.push_back(op_top);

        vector<string> &top = numbers.top();
        top.insert(top.end(), numbers_top.begin(), numbers_top.end());
    }
};

int main() {
    Solution so;
    vector<string> test{"2", "+", "3", "(", "5", "+", "(", "6", "*", "7", ")", ")"};
    auto re = so.convertToRPN(test);
    cout << "result: ";
    for (auto& ele : re) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
