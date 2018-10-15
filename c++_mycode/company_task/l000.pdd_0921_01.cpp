using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2)
    {
        v.push_back(s.substr(pos1, pos2 - pos1));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length())
        v.push_back(s.substr(pos1));
}
void split(const string& s, vector<int>& sv, const char flag = ' ') {
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag)) {
        sv.push_back(stoi(temp));
    }
    return;
}

int main() {
    int n;
    string s;
    vector<int>sv;
    getline(cin, s);
    s = s + " ";
    map<string, int>mpidx;
    map<string, int>cnt;
    bool flag = true;
    string re;
    int maxval = 0;
    for (int i = 0; i < s.size(); i++) {
        //for each letter
        if (s[i] >= 'a' && s[i] <= 'z') {
            re += s[i];
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            re += s[i] + 'a' - 'A';
        }
        else {
            if (re.size() != 0) {
                if (cnt[re] == 0) {
                    mpidx[re] = i;
                }
                cnt[re] += 1;
                maxval = max(maxval, cnt[re]);
            }
            re = "";
        }
    }
    int cnt11 = 0;
    map<string, int>::iterator it = cnt.begin();
    for (; it != cnt.end(); it++) {
        if (it->second == maxval) {
            cnt11++;
        }
    }
    int cntnow = 0;
    for (it = cnt.begin(); it != cnt.end(); it++) {
        if (it->second == maxval) {
            cntnow++;
            if (cntnow != cnt11)
                cout << it->first << " ";
            else
                cout << it->first;
        }
    }
    return 0;
}