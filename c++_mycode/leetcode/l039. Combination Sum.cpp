using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000


//prices{ 2,3,6,7};  7   
// [2��2��3]  [2��3��2]  [3��2��2]  [7]
// ���ֿ����ã��г����list
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
// [2��2��3]  [7]
// ���ֿ����ã��г����set    ������

//prices{ 1,2,3,};  6   
// [1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,2,1] [3,1,2]
// ���ֲ������ã��г����list    

//prices{ 1,2,3,};  6   
// [1,2,3]
// ���ֲ������ã��г����set    ������

// ǰk�������Ϊtarget		�������ݸ�������/��k����ѡ��ѡ
// resultѡ���ظ��벻�ظ�	���ظ����ÿ�ʼλselect or not/ȫ��ѡ��
// ֻ����Ŀ������			dp/backtrack
// set/list					�����벻����  ����֮��Ĭ�����ֵ��� <=
//							ָ��start ѡ�������ֲ�����ѡ��							
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
