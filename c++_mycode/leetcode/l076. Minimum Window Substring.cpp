using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> mp(128, 0);
		for (auto c : t)
			mp[c] += 1; 
		
		int lens = s.size(), count = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end < lens) {
			if (mp[s[end++]]-->0)
				count--;
			while (count == 0) {
				if (d > end - begin) {
					d = end - begin;
					head = begin;
				}
				if (mp[s[begin++]]++ == 0)
					count++;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};

void main()
{
	Solution a;
	string s = "";
	string t = "";
	string x = a.minWindow(s, t);
	cout << x << endl;

}

