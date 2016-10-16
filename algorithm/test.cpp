#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Solution {
public:
    void getNextSecond(string str) {
        vector<int> info = strToInfo(str); 
        calculateNext(info);
        outputResult(info);
    }

    void calculateNext(vector<int>& info) {
        if (info[5] == 59) {
            info[5] = 0;
            if (info[4] == 59) {
                info[4] = 0;
                if (info[3] == 23) {
                    info[3] = 0;
                    calculateDMY(info);
                } else {
                    info[3]++;
                }
            } else {
                info[4]++;
            }
        } else {
            info[5]++;
        }
    }

    void calculateDMY(vector<int>& info) {
        bool is_leap_year = isLeapYear(info[0]);
        int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int carry = 0;
        if (info[1] != 2) {
            if (info[2] == months[info[1]]) {
                info[2] = 1;
                carry = 1;
            } else {
                info[2]++;
            }
        } else {
            if (info[2] == 28 && is_leap_year == false) {
                info[2] = 1;
                carry = 1;
            } else if (is_leap_year == true && info[2] == 29) {
                info[2] = 1;
                carry = 1;
            } else {
                info[2]++;
            }
        }
        if (carry == 1) {
            if (info[1] == 12) {
                info[1] = 1;
                info[0]++;
            } else {
                info[1]++;
            }
        }
    }

    bool isLeapYear(int year) {
        if (year % 400 == 0) {
            return true;
        } else if (year % 100 == 0) {
            return false;
        } else if (year % 4 == 0) {
            return true;
        } else {
            return false;
        }
    }

    vector<int> strToInfo(string& str) {
        vector<int> info(6, 0);
        info[0] = stringToInt(str.substr(0, 4));
        info[1] = stringToInt(str.substr(5, 2));
        info[2] = stringToInt(str.substr(8, 2));
        info[3] = stringToInt(str.substr(11, 2));
        info[4] = stringToInt(str.substr(14, 2));
        info[5] = stringToInt(str.substr(17, 2));
        return info;
    }

    void outputResult(vector<int>& info) {
        cout << setw(4) << setfill('0') << info[0] << "/"
            << setw(2) << info[1] << "/" 
            << setw(2) << info[2] << " "
            << setw(2) << info[3] << ":" 
            << setw(2) << info[4] << ":" 
            << setw(2) << info[5] << endl;
    }

    int stringToInt(string str) {
        int re = 0;
        for (int i = 0; i < str.size(); i++) {
            re = re * 10 + str[i] - '0';
        }
        return re;
    }
};

int main() {
    Solution so;
    string str;
    getline(cin, str);
    so.getNextSecond(str);
    return 0;
}


