using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int temp = 0, maxv = nums[0];
		for (int i = 0; i < nums.size(); i++)
		{
			temp += nums[i];
			maxv = max(maxv, temp);
			temp = max(0, temp);
		}
	return maxv;
	}
};

void main()
{
	Solution a;
	vector<int> nums{ -2,-1 };
	cout << a.maxSubArray(nums) << endl;

}

