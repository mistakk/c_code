using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int len = nums.size(), begin = 0, end = 0, val = 0, d = len+1;
		while (end < len) {
			while (end < nums.size() &&val < s) {
				val += nums[end++];
			}
			while (val >= s) {
				d = min(d, end - begin);
				val -= nums[begin++];
			}
		}
		if (d == len + 1)
			return 0;
		else
			return d;
	}
};

void main()
{
	Solution a;
	vector<int> nums{  1,2,3,4,5 };
	int s = 6;
	cout << a.minSubArrayLen(s, nums) << endl;

}

