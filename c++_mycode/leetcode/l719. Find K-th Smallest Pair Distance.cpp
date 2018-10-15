using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
#include <vector>


class Solution {
public:
	int cntsmallthank(vector<int>&nums, int k) {
		int n = nums.size();
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int left = i;
			int high = n;
			while (left < high - 1) {
				int mid = (left + high) / 2;
				if (nums[mid] - nums[i] > k)
					high = mid;
				else
					left = mid;
			}
			cnt += left - i;
		}
		return cnt;
	}
	int smallestDistancePair(vector<int>& nums, int k) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int left = -2;
		int high = 1 << 20;
		cout << high<<endl;
		while (left < high - 1) {
			int mid = (left + high) / 2;
			int cnt = cntsmallthank(nums, mid);
			if (cnt >= k)
				high = mid;
			else
				left = mid;
		}	
		return high;
	}
};


int main() {
	vector<int>nums{ 1,1,3 };
	Solution a;
	cout << a.smallestDistancePair(nums, 3);

	return 0;
}