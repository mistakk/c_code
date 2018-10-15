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
	int splitArray(vector<int>& nums, int m) {
		long left = nums[0];
		long right = 0;
		for (int i = 0; i < nums.size();i++) {
			if (nums[i] > left)
				left = nums[i];
			right += nums[i];
		}
		if (m == 1)
			return right;
		else if (m == nums.size())
			return left;
		
		long maxval = right;
		while (left <= right) {
			long mid = (left + right) / 2;
			int cnt = 0;
			int i = 0;
			int temp = 0;
			int maxval_temp = 0;
			while (i < nums.size() && cnt<=m) {
				while (i < nums.size() && temp + nums[i] <= mid)
					temp += nums[i++];
				cnt += 1;
				maxval_temp = max(maxval_temp, temp);
				temp = 0;
			}
			if (cnt <= m) {
				right = mid-1;
				if (maxval_temp < maxval)
					maxval = maxval_temp;
			}
			else
				left = mid+1;
		}
		cout << maxval << endl;
		return maxval;
	}
};
int main() {
	vector<int> nums{ 1,2147483646 };
	int m = 1;
	Solution a;
	cout << a.splitArray(nums, m) << endl;

	return 0;
}