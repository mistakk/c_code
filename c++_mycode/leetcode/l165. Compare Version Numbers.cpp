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
    int compareVersion(string version1, string version2) {
        int end1 = 0, end2 = 0, ver1 = 0, ver2 = 0;
        while (end1 < version1.size() || end2 < version2.size()) {
            //for ver1
            while (end1 < version1.size() && version1[end1] != '.') {
                ver1 = ver1 * 10 + version1[end1] - '0';
                end1++;
            }
            
            //for ver2
            while (end2 < version2.size()  && version2[end2] != '.') {
                ver2 = ver2 * 10 + version2[end2] - '0';
                end2++;
            }
            //comp
            if (ver1 < ver2)
                return -1;
            else if (ver1 > ver2)
                return 1;
            end1++, end2++;
            ver1 = 0, ver2 = 0;
        }
        return 0;
    }
};

void main()
{
    Solution a;
    string s1 = "01", s2 = "1";
    cout << a.compareVersion(s1, s2);
}