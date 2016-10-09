#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

/**
 * Describe: Given a bunch of entries(string), each entry has two parts, the first
 * part is the id, the second part is the content. Split the entris into the given
 * size, the entris have the same id should be scattered at best. In other word,
 * each segment should get kinds of id as much as possible. Note: the origin order
 * of the entries should be peserved.
 *
 * Solution:
 *     a. Using a queue to record the position of elements with the same id.
 *     b. Using a min heap to get each turns result. When building the heap,
 *        scattering is the first consideration, and then considering the order.
 *
 * Complexity: O(n * log(count))
 */

class Solution {
public:
    vector<vector<string>> split(vector<string> entries, int count) {
        map<string, int> reflection;
        vector<queue<int>> queues;
        int idx;
        int kind = 0;
        string str;
        // reflection each entry into a queue, the variable kind is the index of 
        // the queue, and the element in the queue is the position int the array 
        // entries whose id is identify.
        for (size_t i = 0; i < entries.size(); i++) {
            // get the id
            idx = entries[i].find_first_of(',');
            str = entries[i].substr(0, idx);

            // insert the entry to the queue
            if (reflection.find(str) == reflection.end()) {
                reflection[str] = kind;
                kind++;
                queues.push_back(queue<int>());
            }
            queues[reflection[str]].push(i);
        }

        // The record is used to manage the heap which mantain the order of the
        // result. The element.first is the index for its correspond queue in 
        // the queues, the element.second is the current level for this kind of 
        // id.
        vector<pair<int, int>> record;
        for (auto& ele : reflection) {
            record.push_back(make_pair(ele.second, 0));
        }

        // The compare function for manage the min heap
        // a. the level of each queue has the higher priority.
        // b. when the level is eqaul the origin order dominant the result.
        // note: this is the reverse operation for max heap, be careful
        auto compare = [&queues](pair<int, int>& ele1, pair<int, int>& ele2) {
            if (ele1.second < ele2.second) {
                return false;
            } else if (ele1.second > ele2.second) {
                return true;
            } else {
                int order1 = queues[ele1.first].front();
                int order2 = queues[ele2.first].front();
                return !(order1 < order2);
            }
        };

        // Make a min heap
        make_heap(record.begin(), record.end(), compare);

        vector<vector<string>> result;

        // total pages
        int pages = (static_cast<int>(entries.size()) - 1) / count + 1; 

        for (int i = 0; i < pages; i++) {
            result.push_back(vector<string>());
            for (int j = 0; j < count && record.size() > 0; j++) {
                // get the top of the heap
                pop_heap(record.begin(), record.end(), compare);

                // get the index of the entry from the heap top correspond queue
                idx = queues[record.back().first].front();

                // push the new element
                result.back().push_back(entries[idx]);

                // increase the level of the queue
                record.back().second++;

                // pop the front of the selected queue and check whether it is 
                // empty if it is empty, this queue need to be removed for there 
                // is no more element it can provide.
                queues[record.back().first].pop();
                if (queues[record.back().first].empty()) {
                    record.pop_back();
                }

                // heaplify the record for the next iteration
                push_heap(record.begin(), record.end(), compare);
            }
        }
        return result;
    }
};

/**
 * Input: A number count represend the length of each segment.
 *        A number n followed by n string with two parts separated by comma. The
 *        first part is the id, the second part is the contend.
 * Output: Element for each segment.
 */
int main() {
    Solution so;
    int count;
    int n;
    vector<string> test;
    string str;

    while (cin >> count){
        cin >> n;
        test.clear();
        while (n-- > 0) {
            cin >> str;
            test.push_back(str);
        }
        auto result = so.split(test, count);
        cout << "result: " << endl;
        for (auto& ele : result) {
            for (auto& c : ele) {
                cout << c << endl;
            }
            cout << endl;
        }
    }
}
