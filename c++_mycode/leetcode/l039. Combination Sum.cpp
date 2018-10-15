using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000


//prices{ 2,3,6,7};  7   
// [2，2，3]  [2，3，2]  [3，2，2]  [7]
// 数字可重用，列出结果list
void dfs2(vector<int> candidates, int target, vector<int> each, vector<vector<int>> & ans) {
	if (target == 0) {
		ans.emplace_back(each);
		return;
	}
	for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
		if (*it <= target) {
			each.emplace_back(*it);
			dfs2(candidates, target - *it, each, ans);
			each.pop_back();
		}
	}
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> each;
	dfs2(candidates, target, each, ans);
	return ans;
}

//prices{ 2,3,6,7};  7   
// [2，2，3]  [7]
// 数字可重用，列出结果set    （排序）

//prices{ 1,2,3,};  6   
// [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]
// 数字不可重用，列出结果list    

//prices{ 1,2,3,};  6   
// [1,2,3]
// 数字不可重用，列出结果set    （排序）

// 前k个数求和为target		设置数据个数变量/第k个数选不选
// result选择重复与不重复	不重复设置开始位select or not/全局选择
// 只求数目不求结果			dp/backtrack
// set/list					排序与不排序  排序之后默认数字递增 <=
//							指定start 选过的数字不能再选了							
void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
void dfs(vector<int> candidates, int target, vector<int> each, vector<vector<int>> & ans) {
	if (target == 0) {
		ans.emplace_back(each);
		show(each);
		return;
	}
	for (vector<int>::iterator it = candidates.begin(); it != candidates.end(); ++it) {
		if (*it > target)
			return;
		if (!each.empty() && *it > each.back())
			continue;
		else{
			each.emplace_back(*it);
			dfs(candidates, target - *it, each, ans);
			each.pop_back();
		}
	}
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int>> ans;
	vector<int> each;
	sort(candidates.begin(),candidates.end());
	dfs(candidates, target, each, ans);
	return ans;
}



void main()
{
	vector<int> candidates{ 2,3,6,7};
	
	vector<vector<int>> ans = combinationSum(candidates, 7);
	int result = ans.size();
	
	cout << result << endl;
}
