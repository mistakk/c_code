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
	int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
		// subarray multiplies equal to k 
		if (k == 0)
			return 0;
		int cnt = 0;
		int sum = 1;
		map<int, int>mp;
		for (int i = 0; i < nums.size(); i++) {
			sum *= nums[i];
			mp[sum] += 1;
			if (sum%k == 0)
				cnt += mp[sum / k];
		}
		return cnt;
	}
	int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
		if (k <= 1)
			return 0;
		int cnt = 0;
		int late = 0;
		int preval = 1;
		for (int i = 0; i < nums.size(); i++) {
			preval *= nums[i];
			while (preval >= k) {
				preval /= nums[late++];
			}
			cnt += i - late + 1;
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