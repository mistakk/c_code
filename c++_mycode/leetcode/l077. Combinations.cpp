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
void dfs2(vector<bool> used, int k, vector<int> each) {
	if (k == 0) {
		ans.emplace_back(each);
		//show(each);
		return;
	}
	for (int i = 0; i < used.size(); i++){
		if (used[i])
			continue;
		if(each.empty() ||i>=each.back())
		{
			each.emplace_back(i+1);
			used[i] = !used[i];
			dfs2(used, k - 1, each);
			each.pop_back();
			used[i] = !used[i];
		}
	}
}
vector<vector<int>> combine2(int n, int k) {
	vector<int> each;
	vector<bool> used(n,false);
	dfs2(used, k, each);
	return ans;
}
void dfs(int start, int now, int k, int n, vector<int> each) {
	if (now == k) {
		ans.emplace_back(each);
		//show(each);
		return;
	}
	for (int i = start; i < n; i++) {
		each.emplace_back(i + 1);
		dfs(i + 1, now + 1, k, n, each);
		each.pop_back();
	}
}
vector<vector<int>> combine(int n, int k) {
	if (k > n)
		return ans;
	vector<int> each;
	int start = 0;
	dfs(0, 0, k, n, each);
	return ans;
}


int main()
{
	int n = 4;
	int k = 2;
	vector<vector<int>> prices = combine(n,k);
	vector<int> d(4, 2);
	cout << d.size();
	return 0;
}
