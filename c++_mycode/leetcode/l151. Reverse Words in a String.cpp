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
    string reverseWords(string &s) {
        int idx = 0;
        while (s[idx] == ' '&&idx<s.size()) {
            idx += 1;
        }
        int endedc = s.size() - 1;
        while (s[endedc] == ' '&&endedc>= idx) {
            endedc -= 1;
        }
        s = s.substr(idx, endedc-idx+1);
        if (s.size() == 0)
            return "";

        reverse(s.begin(), s.end());
        int first = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ' || i == s.size() - 1) {
                if (i == s.size() - 1)
                    end++; 
                reverse(s.begin() + first, s.begin() + end);
                first = end;
                first++;
                while (first < s.size() && s[first] == ' ') {
                    s.erase(s.begin() + first);
                }
                end = first;
            }
            else
                end++;
        }
        return s;
    }
};
void main()
{
    Solution a;
    string ss = " 1112    2  ";
    cout << "'";
    cout << a.reverseWords(ss);
    cout << "'";
}