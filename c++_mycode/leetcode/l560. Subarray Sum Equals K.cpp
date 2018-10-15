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
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> mp; //从起始点到 共mp[x]个点的 和为 x；
		int cnt = 0;
		mp[0] = 1;
		int sum = 0;
		for (auto i : nums) {
			sum += i;			//起始点到最新点的和为sum
			mp[sum] += 1;		//起始点到和为sum的点计数为mp[sum]
			cnt += mp[k - sum];	//起始点到某点的和为sum-k， 中间连续的点和为k   总和为k         中间点的计数为mp[k-sum]
		}
		return cnt;
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