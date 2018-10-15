using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int first = nums.size()-1;
		if (first < 1) 
			return;
		while (first > 0 && nums[first] <= nums[first - 1])
		{
				first--;
		}
		if (!first)
		{
			reverse(nums.begin(), nums.end());
			return;
		}

		int val = nums[first-1];
		int i = nums.size() - 1;
		while (nums[i] <= val)
			i--;
		
		swap(nums[i], nums[first-1]);
		reverse(first + nums.begin(), nums.end());

	}
};

void main()
{
	Solution a;
	vector<int> nums{ 1,3,2 };
	a.nextPermutation(nums);
	for (int i = 0; i < nums.size();i++)
		cout << nums[i] << endl;
}

