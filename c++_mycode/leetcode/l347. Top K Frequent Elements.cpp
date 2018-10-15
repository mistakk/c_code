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
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		std::map<int, int> m;
		for (int i = 0; i < nums.size(); ++i)
			m[nums[i]] += 1;

		std::vector<vector<int>> vec(nums.size() + 1, vector<int>{-1});

		for (std::map<int, int>::iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			int idx = iter->first;
			int cnt = iter->second;
			vec[cnt].push_back(idx);
		}

		std::vector<int> ret;
		for (int i = vec.size()-1; i > 0 ; --i)
		{
			if (vec[i].size() == 1)
				continue;
			for(int j = 1; j<vec[i].size() && k>0;++j,--k)
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
	

	vector<int> te{ 1, 1, 1, 2, 2, 2, 3,3,3 };
	vector<int> ret = a.topKFrequent(te, 2);
	cout << "sys start!" << endl;
	show(ret);



}