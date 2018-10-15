using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	string reverseStr(string s, int k) {
		int fir, end, len = s.size();
		char tmp;
		for (int i = 0; i < len; i = i + 2 * k) {
			if (len - 1 >= k - 1 + i)
				for (int j = 0; j < k/2; j++)
				{
					fir = i + j;
					end = k - 1 + i - j;
					tmp = s[fir];
					s[fir] = s[end];
					s[end] = tmp;
				}
			else
				for (int j = 0; i + 2 * j <= len - 1; j++)
				{
					fir = i + j;
					end = len - 1 - j;
					tmp = s[fir];
					s[fir] = s[end];
					s[end] = tmp;
				}
		}
		return s;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	string s = "abcdefghijabcdefghij";
	cout<<s<<endl;
	Solution a;
	s = a.reverseStr(s,4);
	cout << s << endl;

}