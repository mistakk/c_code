using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>


//16.45
class Solution {
public:
	int maxProfitAssignment_0(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		int ret = 0;
		map<int, int>mp;
		int n = difficulty.size();
		for (int i = 0; i < n; i++) {
			mp[difficulty[i]] = profit[i];
			for (int j = 0; j < n; j++)
				if (difficulty[j] <= difficulty[i] && profit[j] > profit[i])
					mp[difficulty[i]] = profit[j];
		}
		sort(worker.begin(), worker.end());
		map<int, int>::iterator it = mp.begin();
		int tempval = 0;
		for (int i = 0; i < worker.size(); i++) {
			while (it != mp.end() && it->first <= worker[i]) {
				tempval = it->second;
				it++;
			}
			ret += tempval;
		}
		return ret;
	}
	int maxProfitAssignment2(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		vector<pair<int, int>> jobs;
		int N = profit.size(), res = 0, i = 0, maxp = 0;
		for (int j = 0; j < N; ++j) jobs.push_back(make_pair(difficulty[j], profit[j]));
		sort(jobs.begin(), jobs.end()); sort(worker.begin(), worker.end());
		for (int & ability : worker) {
			while (i < N && ability >= jobs[i].first)
				maxp = max(jobs[i++].second, maxp);
			cout << maxp << endl;
			res += maxp;
		}
		return res;
	}

	int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
		int ret = 0, n = difficulty.size(), minval = 1;
		map<int, int>mp;
		vector<int>diff(difficulty.begin(), difficulty.end());
		sort(diff.begin(), diff.end());
		for (int i = 0; i < n; i++) {
			if(mp[difficulty[i]] < profit[i])
				mp[difficulty[i]] = profit[i];
		}
		for (int i = 0; i < n; i++) {
			//minval is the now max money
			//i is the min person index
			//diff[i] is the min person ablility
			//mp[diff[i]] is the min person most money he can get
			if (mp[diff[i]] > minval)
				minval = mp[diff[i]];
			mp[diff[i]] = minval;
		}
		sort(worker.begin(), worker.end());
		map<int, int>::iterator it = mp.begin();
		int tempval = 0;
		for (int i = 0; i < worker.size(); i++) {
			while (it != mp.end() && it->first <= worker[i]) {
				tempval = it->second;
				it++;
			}
			cout << tempval << endl;
			ret += tempval;
		}
		return ret;
	}
};
int main() {
	Solution a;
	vector<int>difficulty{ 66, 1,  28, 73, 53, 35, 45, 60, 100, 44, 59, 94, 27, 88, 7,  18, 83, 18, 72, 63 };
	vector<int>profit    { 66, 20, 84, 81, 56, 40, 37, 82, 53,  45, 43, 96, 67, 27, 12, 54, 98, 19, 47, 77 };
	vector<int>worker{ 1, 10,  23,33, 38,45,53,61,63,68 };//, 94, 18, 28, 78, 100, 16 
	cout << a.maxProfitAssignment(difficulty, profit, worker) << endl;
	return 0;
}