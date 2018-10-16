#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
using namespace std;
void split(const string &s, vector<int> &sv, const char flag = ' ')
{
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag))
    {
        sv.push_back(stoi(temp));
    }
    return;
}
bool checkValidString(string s)
{
    if (s.size() == 0)
        return true;
    int low = 0, high = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            low++;
            high++;
        }
        else if (s[i] == ')')
        {
            low--;
            high--;
        }
        else
        {
            low--;
            high++;
        }
        low = max(0, low);
        if (high < 0)
            return false;
    }
    return low == 0;
}

int main()
{
    string s = "(*";
    cout << checkValidString(s);
    return 0;
}