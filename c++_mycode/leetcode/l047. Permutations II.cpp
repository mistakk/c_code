using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> re;
		dfs(nums, 0, re);
		return re;
	}
	void dfs(vector<int> nums, int i, vector<vector<int>> &re) {
		int len = nums.size();
		if (i == len-1)
			re.push_back(nums);
		else {
			for (int k = i; k < len; k++) {
				if (i!=k && nums[k] == nums[i])
					continue;
				swap(nums[k], nums[i]);
				dfs(nums, i + 1, re);
			}
		}
	}
};
void main()
{
	Solution a;
	vector<int> nums = {1,2,1,2 };
	sort(nums.begin(),nums.end());
	cout << a.permuteUnique(nums).size() << endl;

}

