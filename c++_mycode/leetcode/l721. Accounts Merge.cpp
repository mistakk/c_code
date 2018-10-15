using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>
#include <fstream>
#include <numeric>


class Solution {
public:
	vector<int>father;
	int findp(int x) {
		if (x != father[x])
			father[x] = findp(father[x]);
		return father[x];
	}
	void unionp(int a, int b) {
		int pa = findp(a);
		int pb = findp(b);
		if (pa != pb)
			father[pb] = pa;
	}

	vector<vector<string>> accountsMerge_notsorted(vector<vector<string>>& accounts) {
		vector<vector<string>>res;
		int n = accounts.size();
		if (n == 0) return res;
		father.resize(n * 11, -1);
		map<string, int>mp;
		map<string, int>::iterator it;
		for (int i = 0; i < n; i++) {
			father[i * 11] = i * 11;
			for (int j = 1; j < accounts[i].size(); j++) {
				father[i * 11 + j] = i * 11;
				string now = accounts[i][0] + accounts[i][j];
				it = mp.find(now);
				if (it == mp.end())
					mp[now] = i * 11 + j;
				else
					unionp(it->second, i * 11 + j);
			}
		}
		map<int, int>finish;
		int cnt = -1;
		map<int, int>::iterator it2;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < accounts[i].size(); j++) {
				int pnow = findp(i * 11 + j);
				it2 = finish.find(pnow);
				if (it2 == finish.end()) {
					finish[pnow] = ++cnt;
					res.push_back(vector<string>{ accounts[i][0], accounts[i][j]});
				}
				else {
					if (find(res[finish[pnow]].begin(), res[finish[pnow]].end(), accounts[i][j]) == res[finish[pnow]].end())
						res[finish[pnow]].push_back(accounts[i][j]);
				}
			}
		};
		return res;
	}
	vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		vector<vector<string>>res;
		int n = accounts.size();
		if (n == 0) return res;
		father.resize(n * 11, -1);
		cout << father.size() << endl;
		map<string, int>mp;
		map<string, int>::iterator it;
		for (int i = 0; i < n; i++) {
			father[i * 11] = i * 11;
			for (int j = 1; j < accounts[i].size(); j++) {
				father[i * 11 + j] = i * 11;
				string now = accounts[i][0] + accounts[i][j];
				it = mp.find(now);
				if (it == mp.end())
					mp[now] = i * 11 + j;
				else
					unionp(it->second, i * 11 + j);
			}
		}
		vector<set<string>>ret;
		map<int, int>finish;
		int cnt = -1;
		map<int, int>::iterator it2;
		set<string>::iterator it3;
		for (int i = 0; i < n; i++) {
			for (int j = 1; j < accounts[i].size(); j++) {
				int pnow = findp(i * 11 + j);
				it2 = finish.find(pnow);
				if (it2 == finish.end()) {
					finish[pnow] = ++cnt;
					vector<string> nowvec{ accounts[i][0] };
					res.push_back(nowvec);
					set<string> mmm;
					mmm.insert(accounts[i][j]);
					ret.push_back(mmm);
				}
				else {
					ret[finish[pnow]].insert(accounts[i][j]);
				}
			}
		};
		for (int i = 0; i < res.size(); i++) {
			for (it3 = ret[i].begin(); it3 != ret[i].end(); it3++) {
				res[i].push_back(*it3);
			}
		}
		return res;
	}
};
int main() {
	Solution a;
	vector<int> vec;
	vector<vector<string>> rec{ { "John","johnsmith@mail.com","john_newyork@mail.com" },{ "John","johnsmith@mail.com","john00@mail.com" },{ "Mary","mary@mail.com" },{ "John","johnnybravo@mail.com" } };
	a.accountsMerge(rec);
	return 0;
}