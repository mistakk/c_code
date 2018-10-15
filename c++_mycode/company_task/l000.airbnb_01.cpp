//l000.airbnb_01.cpp
using namespace std;
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <bits.h>

#include <sstream>

// Complete the evaluateActions function below.
void split(const string& s, vector<int>& sv, const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
    return;
}
int findf(vector<int> &father, int x) {
    if (father[x] != x)
        father[x] = findf(father, father[x]);
    return father[x];
}
void unionp(vector<int> &father, int a, int b) {
    int pa = findf(father, a);
    int pb = findf(father, b);
    if (pa != pb) {
        father[pb] = pa;
    }
}
vector<string> evaluateActions(vector<string> actions) {
    int n = actions.size();
    vector<vector<int>>num(n, vector<int>(n, 0));
    vector<string>name(n, "");
    vector<int>action(n, 0);
    vector<bool>support(n, false);
    vector<int>father(n, 0);
    map<string, int>mp;

    for (int i = 0; i < n; ++i) {
        istringstream iss(actions[i]);
        string temp;
        vector<string>sv;
        while (getline(iss, temp, ' ')) {
            sv.push_back(temp);
        }
        father[i] = i;
        name[i] = sv[1];
        mp[name[i]] = i;
    }

    for (int i = 0; i < n; ++i) {
        istringstream iss(actions[i]);
        string temp;
        vector<string>sv;
        while (getline(iss, temp, ' ')) {
            sv.push_back(temp);
        }
        if (sv[2].compare("move") == 0) {
            num[mp[sv[1]]][mp[sv[3]]] = 1;
            action[i] = mp[sv[3]];
        }
        else if (sv[2].compare("support") == 0) {
            num[mp[sv[1]]][mp[sv[3]]] = 2;
            action[i] = -mp[sv[3]];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (num[i][j] == 1)
                support[j] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (support[i] && num[i][j] == 2)
                unionp(father, i, j);
    }
    for (int i = 0; i < n; i++) {
        findf(father, i);
    }

    set<int>place;//团队
    for (int i = 0; i < n; i++)
        place.insert(father[i]);

    vector<vector<int>>cntt(n);//团队 人数
    for (int i = 0; i < n; i++) {
        cntt[father[i]].push_back(i);
    }
    vector<vector<int>>fight(n);//战场：团队

    map<int, int>people;
    for (int i = 0; i < n; i++) {
        if (cntt[i].size() == 0)//团队没有人
            continue;
        for (int j = 0; j < cntt[i].size(); ++j) {//遍历该团队每一个成员
            if (action[cntt[i][j]] > 0) {//该成员是主节点
                int target = action[i];//被攻击的目标
                fight[target].push_back(cntt[i][j]);//被攻击的目标，填进一个主节点
                people[cntt[i][j]] = cntt[i].size();//这个团队人数
            }
        }
    }

    vector<int>live(n, 0);

    for (int i = 0; i < n; i++) {//遍历每一个战场
        int winner = -1;
        int maxval = -1;
        for (int j = 0; j < fight[i].size(); j++) {
            if (maxval < people[fight[i][j]]) {
                maxval = people[fight[i][j]];
                winner = fight[i][j];
            }
        }
        int cnt = 0;
        for (int j = 0; j < fight[i].size(); j++) {
            if (people[fight[i][j]] == maxval)
                cnt++;
        }
        if (cnt > 1)
            for (int j = 0; j < fight[i].size(); j++) {
                int deadleader = father[fight[i][j]];
                for (int j = 0; j < n; j++) {
                    if (father[j] == deadleader)
                        live[j] = 0;
                }
            }
        else {
            for (int j = 0; j < fight[i].size(); j++) {
                int deadleader = father[fight[i][j]];
                if (deadleader != winner)
                    for (int j = 0; j < n; j++) {
                        if (father[j] == deadleader)
                            live[j] = 0;
                    }
                else {
                    for (int j = 0; j < n; j++) {
                        if (father[j] == deadleader)
                            live[j] = action[i];
                    }
                }
            }
        }
    }

    vector<string>ret(n);
    string to_string();
    for (int i = 0; i < n; i++) {
        string s = "A ";
        s[0] += i;

        if (live[i] == -1) {
            s += "[dead]";
        }
        else {
            s += name[live[i]];
        }
        ret[i] = s;
    }

    return ret;

}



int main() {
    return 0;
}