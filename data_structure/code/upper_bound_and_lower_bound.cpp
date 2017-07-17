#include <iostream>
#include <vector>

using namespace std;

/**
 * Find the upper bound of target, find the position it need to insert.
 * End is not included.
 */
int upper_bound(vector<int> &vec, int beg, int end, int target) {
    int mid = 0;
    int l = beg;
    int r = end;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (vec[mid] <= target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return r;
}

/**
 * Find the lower bound of the target, find the position it need to insert.
 * End is not included.
 */
int lower_bound(vector<int> &vec, int beg, int end, int target) {
    int mid = 0;
    int l = beg;
    int r = end;
    while (l < r) {
        mid = l + (r - l) / 2;
        if (vec[mid] < target) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}
