#include <bits/stdc++.h>

using namespace std;

/* 3 - state
 * 2 - accept states
 * 6 - movement number
 *
 * 0 2 - accept states
 *
 * 3 2 6
 * 0 2
 * 1 a 1  - from 0 number of moves
 * 2 b 1 c 2  - from 1 number of moves
 * 3 0 2 1 2 a 1  - from 2 number of moves
 * */

string str;
int num, number;
char ch;
int n, a, t;
set<int> accepts;
map<int, map<char, vector<int>>> moves;

int main() {
    cin >> str;
    cin >> n >> a >> t;
    for (int i = 0; i < a; ++i) {
        cin >> num;
        accepts.insert(num);
    }
    for (int i = 0; i < n; ++i) {
        cin >> num;

        map<char, vector<int>> mp;
        for (int j = 0; j < num; ++j) {
            vector<int> v;
            cin >> ch;
            cin >> number;

            if (mp.find(ch) == mp.end()) {
                v.push_back(number);
                mp.insert({ch, v});
            } else {
                mp.find(ch)->second.push_back(number);
            }
        }
        moves.insert({i, mp});
    }
    string res = "";
    set<int> currStates;
    set<int> nextStates;
    currStates.insert(0);

    for (char i : str) {
        ch = i;
        bool boo = true;
        for (int curr: currStates) {
            map<char, vector<int>> m = moves.find(curr)->second;
            if (m.find(ch) == m.end()) continue;

            vector<int> v = m.find(ch)->second;
            for (int j : v) {
                nextStates.insert(j);
                if (accepts.find(j) != accepts.end() && boo) {
                    res += "Y";
                    boo = false;
                }
            }
        }
        if (boo || currStates.empty()) res += "N";

        currStates.clear();
        for (int curr: nextStates)
            currStates.insert(curr);

        nextStates.clear();
    }
    cout << res << endl;

    return 0;
}
