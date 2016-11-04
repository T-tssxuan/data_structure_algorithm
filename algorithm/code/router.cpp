#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Status for each subtree with x routers
struct Status {
    int rate;
    bool is_chosen; // the room is set router
    bool is_cover; // the room is cover by router
    vector<int> components; // the combine of subtree forms this tree
    Status(): rate(0), is_chosen(false), is_cover(false), components(3, 0) {}
};

// Recorder for each room
struct Recorder {
    bool is_set;
    vector<Status> status;
    Recorder(int router_num): status(router_num + 1, Status()){}
};

// The adjacent table data structure
using AdjTable = vector<vector<int>>;

class Solution {
private:
    AdjTable table;
    vector<int> statisfactions;
    int router_num;
    int room_num;
    vector<Recorder> recorders;
public:
    Solution(AdjTable table, vector<int> statisfactions, int router_num):
        table(table), statisfactions(statisfactions), router_num(router_num) {
            room_num = table.size();
            recorders = vector<Recorder>(room_num, Recorder(router_num));
        }
    int getMaxSatisfaction() {
        int start_room = 1;
        int tmp = 0;
        // make sure the start room is not the node with three door
        // if it is we change the start room
        while (table[start_room].size() == 3) {
            tmp = table[start_room].back();
            table[start_room].pop_back();
            table[tmp].push_back(start_room);
            // alter
            swap(table[tmp][0], table[tmp].back());
            start_room = tmp;
        }

        // recursive from the start_room
        initSubTreeRecord(start_room);
        return recorders[start_room].status[router_num].rate;
    }
    void initSubTreeRecord(int room_id) {
        // if the room node visited recursive visit it and it's subroom(or tree)
        if (!recorders[room_id].is_set) {
            recorders[room_id].is_set = true;
            switch (table[room_id].size()) {
                case 0: // if the tree has no subtree
                    setSatisfaction_0(room_id);
                    break;
                case 1: // if the tree has one subtree
                    setSatisfaction_1(room_id);
                    break;
                case 2: // if the tree has two subtree
                    setSatisfaction_2(room_id);
                    break;
                default:
                    break;
            };
        }
    }
    // tree has no subtree
    // all it's value is identity
    void setSatisfaction_0(int room_id) {
        for (int i = 1; i <= router_num; i++) {
            recorders[room_id].status[i].rate = statisfactions[room_id];
            recorders[room_id].status[i].is_chosen = true;
            recorders[room_id].status[i].is_cover = true;
        }
    }
    // tree has one subtree
    // it's root value depends on the subtree
    void setSatisfaction_1(int room_id) {
        int sub_room_id = table[room_id][0];
        int sat_set, sat_not_set;
        vector<int> components(3, 0);
        initSubTreeRecord(sub_room_id);
        for (int i = 1; i <= router_num; i++) {
            // root is placed a router so it's subtree can only place i - 1
            // routers
            sat_set = recorders[sub_room_id].status[i - 1].rate \
                      + statisfactions[room_id];
            if (!recorders[sub_room_id].status[i - 1].is_cover) {
                sat_set += statisfactions[sub_room_id];
            }

            // root is not placed router so it's subtree can place i - 1 routers
            sat_not_set = recorders[sub_room_id].status[i].rate;
            if (recorders[sub_room_id].status[i].is_chosen) {
                sat_not_set += statisfactions[room_id];
            }

            // get the maximum one as the result
            if (sat_set >= sat_not_set) {
                recorders[room_id].status[i].is_chosen = true;
                recorders[room_id].status[i].is_cover = true;
                recorders[room_id].status[i].rate = sat_set;
                recorders[room_id].status[i].components[0] = i - 1;
            } else {
                recorders[room_id].status[i].is_chosen = false;
                if (recorders[sub_room_id].status[i - 1].is_chosen) {
                    recorders[room_id].status[i].is_cover = true;
                } else {
                    recorders[room_id].status[i].is_cover = false;
                }
                recorders[room_id].status[i].is_cover = true;
                recorders[room_id].status[i].rate = sat_not_set;
                recorders[room_id].status[i].components[0] = i;
            }
        }
    }
    void setSatisfaction_2(int room_id) {
        int sub_room_l = table[room_id][0];
        int sub_room_r = table[room_id][1];

        initSubTreeRecord(sub_room_l);
        initSubTreeRecord(sub_room_r);

        int router_l;
        int router_r;

        int tmp_max_rate = 0;
        int tmp_com_l = 0;
        int tmp_com_r = 0;
        bool is_cover;
        bool cur_cover;

        int tmp;

        // current root is not placed router
        for (int cur_router = 1; cur_router <= router_num; cur_router++) {
            tmp_max_rate = tmp_com_l = tmp_com_r = 0;
            is_cover = false;
            for (router_l = 0; router_l <= cur_router; router_l++) {
                router_r = cur_router - router_l;
                tmp = 0;
                cur_cover = false;

                // the current root is not covered by wifi, howevere if either
                // of it's subtree root which is placed a router, it will be
                // covered by wifi, we need include the bonus
                if (recorders[sub_room_l].status[router_l].is_chosen
                        || recorders[sub_room_r].status[router_r].is_chosen) {
                    tmp += statisfactions[room_id];
                    cur_cover = true;
                }
                tmp += recorders[sub_room_l].status[router_l].rate;
                tmp += recorders[sub_room_r].status[router_r].rate;
                if (tmp > tmp_max_rate) {
                    tmp_max_rate = tmp;
                    tmp_com_l = router_l;
                    tmp_com_r = router_r;
                    is_cover = cur_cover;
                }
            }
            recorders[room_id].status[cur_router].rate = tmp_max_rate;
            recorders[room_id].status[cur_router].is_cover = is_cover;
            recorders[room_id].status[cur_router].components[0] = tmp_com_l;
            recorders[room_id].status[cur_router].components[1] = tmp_com_r;
        }

        // current root is palced a router and compare the previous value,
        // get the maximum rate state as the result
        for (int cur_router = 1; cur_router <= router_num; cur_router++) {
            tmp_max_rate = tmp_com_l = tmp_com_r = 0;
            for (router_l = 0; router_l <= cur_router - 1; router_l++) {
                router_r = cur_router - 1 - router_l;

                tmp = statisfactions[room_id];
                tmp += recorders[sub_room_l].status[router_l].rate;
                tmp += recorders[sub_room_r].status[router_r].rate;

                // if subtree root isn't covered by wifi, they will be covered
                // by wifi which comes from the current root
                if (!recorders[sub_room_l].status[router_l].is_cover) {
                    tmp += statisfactions[sub_room_l];
                }
                if (!recorders[sub_room_r].status[router_r].is_cover) {
                    tmp += statisfactions[sub_room_r];
                }

                if (tmp > tmp_max_rate) {
                    tmp_max_rate = tmp;
                    tmp_com_l = router_l;
                    tmp_com_r = router_r;
                }
            }

            // compare and get the greater one
            if (tmp_max_rate >= recorders[room_id].status[cur_router].rate) {
                recorders[room_id].status[cur_router].is_chosen = true;
                recorders[room_id].status[cur_router].is_cover = true;
                recorders[room_id].status[cur_router].rate = tmp_max_rate;
                recorders[room_id].status[cur_router].components[0] = tmp_com_l;
                recorders[room_id].status[cur_router].components[1] = tmp_com_r;
            }
        }
    }
    void swap(int& num1, int& num2) {
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
};


int main(int argc, char* argv[]) {
    int n, m;
    int tmp1, tmp2;
    cin >> n;
    cin >> m;
    vector<int> statisfactions(n + 1, 0);
    AdjTable table(n + 1, vector<int>());
    vector<vector<int>> bidirection_grap(n + 1, vector<int>());
    vector<bool> visited(n + 1, false);

    // input the statisfaction of each room
    for (int i = 1; i <= n; i++) {
        cin >> tmp1;
        statisfactions[i] = tmp1;
    }

    // construct the bidirection grap
    for (int i = 1; i < n; i++) {
        cin >> tmp1;
        cin >> tmp2;
        bidirection_grap[tmp1].push_back(tmp2);
        bidirection_grap[tmp2].push_back(tmp1);
    }

    // construct the ajacent table from the bidirection table, this adjacent
    // table is undirected grap
    queue<int> room_queue;
    room_queue.push(1);
    while (!room_queue.empty()) {
        int top = room_queue.front();
        visited[top] = true;
        room_queue.pop();
        for (size_t i = 0; i < bidirection_grap[top].size(); i++) {
            if (!visited[bidirection_grap[top][i]]) {
                table[top].push_back(bidirection_grap[top][i]);
                room_queue.push(bidirection_grap[top][i]);
            }
        }
    }

    Solution so(table, statisfactions, m);
    auto re = so.getMaxSatisfaction();
    cout << re << endl;
    return 0;
}
