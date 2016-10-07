#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Describe:
 * Merge the pairs [start_point, end_point, heighht], with the highers covers
 * the lower when the range overlapped.
 */


class Solution {
public:
    vector<vector<int> > buildingOutline(vector<vector<int> > &buildings) {
        vector<vector<int>> result;
        // The start point of the heap
        size_t start = 0;
        // The end point of the heap
        size_t end = buildings.size();
        vector<int> tmp {0, 0, 0};

        // the compare function
        auto compare = [](vector<int>& vec1, vector<int>& vec2) {
            return !(vec1[0] < vec2[0]);
        };
        // make the buildings vector becomes a min heap
        make_heap(buildings.begin() + start, buildings.begin() + end, compare);

        // get all element in the heap
        while (start < end) {
            // get the minest element in the heap
            pop_heap(buildings.begin() + start, buildings.begin() + end, compare);

            if (tmp[2] == 0) {
                // if result empty just skip
                tmp = buildings[end - 1];
                end--;
            } else if (tmp[2] == buildings[end - 1][2]){
                // the height of the newer equals the tail
                if (tmp[1] >= buildings[end - 1][0]) {
                    // overlapped: update the range
                    tmp[1] = tmp[1] > buildings[end - 1][1]? \
                             tmp[1] : buildings[end - 1][1];
                } else {
                    // no overlap, push to result and continue
                    push_result(result, tmp);
                    tmp = buildings[end - 1];
                }
                end--;
            } else if (tmp[2] < buildings[end - 1][2]) {
                // the height of the newer higher than the tail
                if (tmp[1] <= buildings[end - 1][1]) {
                    tmp[1] = tmp[1] < buildings[end - 1][0]? \
                             tmp[1] : buildings[end - 1][0];
                    push_result(result, tmp);

                    tmp = buildings[end - 1];
                    end--;
                } else {
                    int tmp_end = tmp[1];
                    int tmp_hight = tmp[2];

                    tmp[1] = buildings[end - 1][0];
                    push_result(result, tmp);

                    tmp = buildings[end - 1];
                    buildings[end - 1][0] = buildings[end - 1][1];
                    buildings[end - 1][1] = tmp_end;
                    buildings[end - 1][2] = tmp_hight;
                    push_heap(buildings.begin() + start, buildings.begin() + end, compare);
                }
            } else if (tmp[2] > buildings[end - 1][2]) {
                // the height of the newer lower than the tail
                if (tmp[1] >= buildings[end - 1][1]) {
                    end--;
                } else if (tmp[1] <= buildings[end - 1][0]) {
                    push_result(result, tmp);
                    tmp = buildings[end - 1];
                    end--;
                } else {
                    buildings[end - 1][0] = tmp[1];
                    push_heap(buildings.begin() + start, buildings.begin() + end, compare);
                }
            }
        }
        if (tmp[2]) {
            result.push_back(tmp);
        }
        return result;
    }
    void push_result(vector<vector<int>>& result, vector<int>& tmp) {
        // process the new result
        if (tmp[0] != tmp[1]) {
            // with range greater than 0
            if (result.size() && result.back()[2] == tmp[2]
                    && result.back()[1] == tmp[0]) {
                // duplicated with the previous result
                result.back()[1] = tmp[1];
            } else {
                // the brand new one
                result.push_back(tmp);
            }
        }
    }

};

/**
 * Input: a N with N * 3 number
 * Ouput: [start_point, end_point, height] each row
 */
int main() {
    Solution so;
    vector<vector<int>> test;
    int n;
    vector<int> unit(3, 0);
    while (cin >> n) {
        test.clear();
        while (n-- > 0) {
            for (int i = 0; i < 3; i++) {
                cin >> unit[i];
            }
            test.push_back(unit);
        }
        auto re = so.buildingOutline(test);
        for (auto& ele : re) {
            cout << "[";
            cout << ele[0] << "," << ele[1] << "," << ele[2];
            cout << "]" << endl;
        }
        cout << endl;
    }
    return 0;
}
