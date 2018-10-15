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
	int firstUniqChar(string s) 
	{
		std::map<char, int> m;
		for(int i = 0; i <s.size();++i)
			if (m[s[i]] == 0)
				m[s[i]] = -i-1;
			else
				m[s[i]] = 1;
		int ret = INT_MIN;
		for (std::map<char, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
			if (iter->second <0 && iter->second > ret)
				ret = iter->second;
		if (ret!= INT_MIN)
			return -ret-1;
		return -1;
	}
};


void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	int ret = a.firstUniqChar("cabb");


	cout << "sys start!" << endl;
	cout << ret << endl;
	
	vector<int> te{ 5,1 };


}