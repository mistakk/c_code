using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int add = 0, idx1 = 0, idx2 = 0;
        string ret;
        while (idx1 < a.size() || idx2 < b.size() || add != 0) {
            int result = add;
            if (idx1 != a.size())
                result += a[idx1++] - '0';
            if (idx2 != b.size())
                result += b[idx2++] - '0';
            ret += result % 2 + '0';
            add = result / 2;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

void main()
{
    Solution a;
    string s1 = "10", s2 = "0";
    cout << a.addBinary(s1, s2) << endl;
}