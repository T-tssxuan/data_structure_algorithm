#include <iostream>
#include <vector>

using namespace std;

/**
 * The heap make and maintance algorithm which based on the array.
 * make_heap: make a heap in the range start and end
 * heaplifyTB: heaplify from top to bottom
 * heaplifyBT: heaplify from bottom to top
 * swap: swap two element
 */
class Heap{
public:
    /**
     * compare of the the heap when '<' the small heap, or the big heap
     * params:
     *  val1: the first value to compare
     *  val2: the second value to compare
     */
    bool compare(int val1, int val2) {
        return val1 < val2;
    }
    /**
     * make a heap in a array[start - end), in place
     * params:
     *  nums: the base array
     *  start: the start index of the range
     *  end: the end of the range(not include)
     */
    void make_heap(vector<int>& nums, int start, int end) {
        int cur = start + (end - start - 1) / 2;
        while (cur >= start) {
            heaplifyTB(nums, cur, nums.size());
            cur--;
        }
    }
    /**
     * heaplify the pos to till the leave(top --> bottom)
     * params:
     *  nums: the base array
     *  pos: the position need to heaplify
     *  end: the end of the range(not include)
     */
    void heaplifyTB(vector<int>& nums, size_t pos, size_t end) {
        size_t left = 2 * pos + 1;
        size_t right = 2 * pos + 2;
        size_t target = pos;
        if (left >= end) {
            return;
        }
        target = compare(nums[target], nums[left])? target : left;
        if (right < end) {
            target = compare(nums[target], nums[right])? target : right;
        }
        swap(nums, pos, target);
        if (target == left) {
            heaplifyTB(nums, left, end);
        } else if (target == right) {
            heaplifyTB(nums, right, end);
        }
    }
    /**
     * heaplify the position till the root(bottom --> top)
     * params:
     *  nums: the base array
     *  start: the root position
     *  pos: the positon need to heaplify
     */
    void heaplifyBT(vector<int>& nums, size_t start, size_t pos) {
        size_t cur = pos;
        size_t parent;
        while (cur > start) {
            parent = (cur - 1) / 2; 
            if (compare(nums[cur], nums[parent])) {
                swap(nums, cur, parent);
                cur = parent;
            } else {
                break;
            }
        }
    }
    /**
     * get the top of the heap
     * params:
     *  nums: the base array
     *  start: the start of the range index
     *  end: the end of the range index(not include)
     * return:
     *  the position of the top which is the new end of the heap
     */
    size_t getTop(vector<int>& nums, size_t start, size_t end) {
        swap(nums, start, end - 1);
        heaplifyTB(nums, start, end);
        return end - 1;
    }
    /**
     * swap tow element in the array
     * params:
     *  nums: the base array
     *  pos1: the first position need to swap
     *  pos2: the second position need to swap
     */
    void swap(vector<int>& nums, size_t pos1, size_t pos2) {
        int tmp = nums[pos1];
        nums[pos1] = nums[pos2];
        nums[pos2] = tmp;
    }
};

int main() {
    Heap so;
    vector<int> test{4, -10, 5, 1, 3, 2, 8, 9};
    so.make_heap(test, 0, test.size());
    cout << "beginning: ";
    for (auto ele : test) {
        cout << ele << " ";
    }
    cout << endl;
    test.push_back(-3);
    so.heaplifyBT(test, 0, test.size() - 1);
    cout << "insert: ";
    for (auto ele : test) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
