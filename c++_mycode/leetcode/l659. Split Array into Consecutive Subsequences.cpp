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
	bool isPossible(vector<int>& nums) {
		std::map<int, int> cnt, tail;
		for (int i : nums)
			cnt[i]++;
		for (int i : nums)
		{
			if (cnt[i] == 0)
				continue;
			cnt[i]--;
			if (tail[i - 1] > 0)
			{
				tail[i - 1]--;
				tail[i]++;
			}
			else if (cnt[i + 1] && cnt[i + 2])
			{
				cnt[i + 1]--;
				cnt[i + 2]--;
				tail[i + 2]++;
			}
			else
				return false;
		}
		return true;
	}
};


void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	vector<int> te{ 5,1 };


}