using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> re;
		int n = nums.size();
		vector<bool> used(n,true);
		vector<int> temp;
		dfs(n, 0, used, temp, nums, re);
		return re;
	}
	void dfs(int n, int now, vector<bool> &used,vector<int> &temp,vector<int> nums, vector<vector<int>> &re) {
		if (n == now)
			re.push_back(temp);
		else
			for (int i = 0; i < nums.size(); i++) {
				if (used[i]){
					used[i] = false;
					temp.push_back(nums[i]);
					dfs(n, now + 1, used, temp, nums,re);
					temp.pop_back();
					used[i] = true;
				}
			}
	}
	vector<vector<int>> permute2(vector<int>& nums) {
		vector<vector<int>> re;
		dfs2(nums, 0, re);
		return re;
	}
	void dfs2(vector<int>& nums, int i, vector<vector<int>> &re) {
		int len = nums.size();
		if (i == len)
			re.push_back(nums);
		else
		{
			for (int k = i; k < len; k++) 
			{
				swap(nums[i], nums[k]);
				dfs2(nums, i + 1, re);
			}
		}
	}



};
void main()
{
	Solution a;
	vector<int> nums{ 1,2,3,5,6 };
	vector<vector<int>>  re = a.permute2(nums);
	cout << re.size() << endl;
}

