using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int gi = g.size() - 1, si = s.size() - 1;
		int cnt = 0;
		while (gi >= 0 && si >= 0) 
		{
			while (gi >= 0) 
			{
				if (s[si] >= g[gi])
				{
					si--;
					gi--;
					cnt++;
					break;
				}
				else
					gi--;
			}
		}
		return cnt;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<int> s{ 1,2,3 };
	vector<int> g{ 1,1,3 };
	int ret = a.findContentChildren(g, s);
	cout << "sys start!" << endl;
	cout << ret << endl;


}