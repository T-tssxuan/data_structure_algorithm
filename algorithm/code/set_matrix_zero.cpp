#include <iostream>
#include <vector>

using namespace std;

/**
 * Describe: Given a m x n matrix, if an element is 0, set its entire row and 
 * column to 0. Do it in place. Do it in place.
 */

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0) {
            return;
        }
        int row = 0;  // record the [0, 0] element.
        int col = 0;  // record the [0, 0] element
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                    if (i == 0) {
                        row = 1;
                    }
                    if (j == 0) {
                        col = 1;
                    }
                }
            }
        }
        for (size_t i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (size_t j = 0; j < matrix[i].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (size_t j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (size_t i = 0; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }
        // set the first row
        if (row == 1) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
        // set the first column
        if (col == 1) {
            for (size_t i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};

int main() {
    return 0;
}
