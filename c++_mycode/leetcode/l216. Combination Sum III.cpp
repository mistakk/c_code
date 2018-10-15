using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INT_MAX 0x7fffffff

#define INT_MIN 0x80000000

void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
vector<vector<int>> ans;
void dfs(int start, int now, int target, int k_now, int k, vector<int> each) {
	if (now == target && k_now==k) {
		ans.emplace_back(each);
		show(each);
		return;
	}
	for (int i = start; i < 9; i++) {
		if (i+now <= target && k_now<k) {
			//dfs(i + 1, now, target, k, n, each);
			each.emplace_back(i + 1);
			dfs(i + 1, now + i + 1, target, k_now+1, k,each);
			each.pop_back();
		}
	}
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<int> each;
	dfs(0, 0, n, 0, k, each);
	return ans;
}


int main()
{
	int n = 9;
	int k = 3;
	vector<vector<int>> prices = combinationSum3(k, n);
	return 0;
}
