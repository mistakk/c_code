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
	vector<int> smallestRange(vector<vector<int>>& nums) {
		int k = nums.size();
		vector<int> cnt(k, 0);
		map<int, vector<int>>mp;
		for (int i = 0; i < k; i++) {
			int n = nums[i][0];
			mp[n].push_back(i);
		}
		vector<int> result(2, 0);
		int minval = INT_MAX;
		while (1) {
			auto it1 = mp.begin();
			auto it2 = prev(mp.end());
			int aa = (*it1).first;
			int bb = (*it2).first;
			if (bb - aa < minval) {
				minval = bb - aa;
				result[0] = aa;
				result[1] = bb;
			}
			vector<int> res = (*it1).second;
			mp.erase(it1);
			for (int i : res) {
				cnt[i]++;
				if (cnt[i] >= nums[i].size())
					return result;
				int num = nums[i][cnt[i]];
				mp[num].push_back(i);
			}
		}
		return result;
	}

	vector<int> smallestRange11(vector<vector<int>>& nums) {
		int k = nums.size();
		map<int, vector<int>> m;
		vector<int> cnt(k, 0);
		for (int i = 0; i < k; i++) {
			int n = nums[i][cnt[i]];
			m[n].push_back(i);
		}

		int minr = INT_MAX;
		vector<int> result(2);
		while (true) {
			auto it1 = m.begin();
			auto it2 = prev(m.end());
			int st = (*it1).first;
			int ed = (*it2).first;
			if (ed - st < minr) {
				minr = ed - st;
				result[0] = st;
				result[1] = ed;
			}
			vector<int> v = (*it1).second;
			m.erase(it1);
			for (int i : v) {
				cnt[i]++;
				if (cnt[i] >= nums[i].size())
					return result;
				int num = nums[i][cnt[i]];
				m[num].push_back(i);
			}
		}
	}
};

void show(vector<int> vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] <<endl;
	cout << endl;
}

void main()
{
	Solution a;
	vector<vector<int>>nums{ { 0,9,12,20,99 },{4,5,15,24,26,99},{5,18,22,30,99}};
	vector<int> ret = a.smallestRange(nums);
	show(ret);

}