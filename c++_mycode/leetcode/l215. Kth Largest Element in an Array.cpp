using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>



class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		int size = nums.size();
		if (0 == size || k > size)
			return 0;
		make_heap(nums.begin(), nums.end());
		int ret = 0;
		for (int i = 0; i < k - 1; i++)
		{
			pop_heap(nums.begin(), nums.end());
			nums.pop_back();
		}
		return nums[0];
	}
};




void main()
{
	//Solution a;
	//vector<int> nums = { 10,20,30,5,15 };
	//cout << a.findKthLargest(nums, 1);
}









