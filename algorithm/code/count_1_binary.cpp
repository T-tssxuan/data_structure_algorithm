#include <iostream>
using namespace std;

class Solution {
public:
    int countOnes(int num) {
        int count = 0;
        unsigned int tmp = num;
        while (tmp > 0) {
            tmp = tmp & (tmp - 1);
            ++count;
        }
        return count;
    }
};

int main() {
    Solution so;
    int n;
    while (cin >> n) {
        auto re = so.countOnes(n);
        cout << "result: " << re << endl;
    }
    return 0;
}
