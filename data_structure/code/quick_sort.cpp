#include <vector>
#include <iostream>

using namespace std;

/**
 * Describe: The quick sort implement, based on the lomuto partition and the 
 * hoare partition.
 *
 * Detail: https://en.wikipedia.org/wiki/Quicksort
 */

class quick_sort{
private:
    void swap(int& a, int& b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int lomuto_partition(vector<int>& nums, size_t lo, size_t hi) {
        int pivot = nums[hi];
        size_t beg = lo;
        size_t i = lo;
        while (i < hi) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[beg]);
                ++beg;
            }
            ++i;
        }
        swap(nums[hi], nums[i]);
        return i;
    }
    int hoare_partition(vector<int>& nums, size_t lo, size_t hi) {
        int pivot = nums[lo];
        int beg = lo;
        int end = hi;
        while (true) {
            while(nums[beg] < pivot) {
                ++beg;
            }
            while(nums[end] > pivot) {
                --end;
            }
            if (beg >= end) {
                return end;
            }
            swap(nums[beg], nums[end]);
        }
        return -1;
    }
public:
    void sort_base_lomuto_partition(vector<int>& nums, int lo, int hi) {
        if (lo < hi) {
            // p should be a signed int, in case of it is 0
            int p = lomuto_partition(nums, lo, hi);
            cout << "lomuto p: " << p << endl;
            sort_base_lomuto_partition(nums, lo, p - 1);
            sort_base_lomuto_partition(nums, p + 1, hi);
        }
    }
    void sort_base_hoare_partition(vector<int>& nums, int lo, int hi) {
        if (lo < hi) {
            // p should be a signed int, in case of it is 0
            int p = lomuto_partition(nums, lo, hi);
            cout << "hoare p: " << p << endl;
            sort_base_hoare_partition(nums, lo, p - 1);
            sort_base_hoare_partition(nums, p + 1, hi);
        }
    }
};

int main(int argc, char **argcv) {
    quick_sort qs;
    vector<int> test1{5, 4, 3, 2, 1};
    qs.sort_base_lomuto_partition(test1, 0, 4);
    cout << "Test1: Quick sort based on lomuto partition: ";
    for (auto ele : test1) {
        cout << ele << " ";
    }
    cout << endl;

    vector<int> test2{1, 2, 3, 5, 4};
    qs.sort_base_hoare_partition(test2, 0, 4);
    cout << "Test1: Quick sort based on hoare partition: ";
    for (auto ele : test2) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
