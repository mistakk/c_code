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
void show(vector<string> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) 
	{
		std::map<string, int> m;
		for (int i = 0; i < words.size(); ++i)
			m[words[i]] += 1;

		std::vector<vector<string>> vec(words.size() + 1, vector<string>{""});

		for (std::map<string, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			string idx = iter->first;
			int cnt = iter->second;
			vec[cnt].push_back(idx);
		}

		std::vector<string> ret;
		for (int i = vec.size() - 1; i > 0; --i)
		{
			if (vec[i].size() == 1)
				continue;
			for (int j = 1; j<vec[i].size() && k>0; ++j, --k)
				ret.push_back(vec[i][j]);
			if (k == 0)
				break;
		}
		return ret;
	}
};


void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;


	vector<string> te{ "the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is" };
	vector<string> ret = a.topKFrequent(te, 4);
	cout << "sys start!" << endl;
	show(ret);



}