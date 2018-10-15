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




class Solution2 {
public:
	vector<int> father;
	int count;
	int findp(int a) {
		if (a != father[a])
			father[a] = findp(father[a]);
		return father[a];
	}
	void unionp(int a, int b) {
		int pa = findp(a);
		int pb = findp(b);
		if (pa != pb) {
			father[pb] = pa;
			count--;
		}
	}
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		if (n == 0) return 0;
		int m = M[0].size();
		if (m == 0) return 0;
		father.resize(n*m, -1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (M[i][j] == 1) {
					father[i*m + j] = i * m + j;
					count += 1;
				}
		}
		vector<int> di{ -1,0,0,1 };
		vector<int> dj{ 0,-1,1,0 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (M[i][j] == 1)
					for (int k = 0; k < 3; k++) {
						if (i + di[k] >= 0 && i + di[k] < n && j + dj[k] >= 0 && j + dj[k] < m && M[i + di[k]][j + dj[k]] == 1)
							unionp(i*m + j, (i + di[k])*m + j + dj[k]);
					}
		}
		return count;
	}
};
class Solution {
public:
	vector<int> father;
	int count;
	int findp(int a) {
		if (a != father[a])
			father[a] = findp(father[a]);
		return father[a];
	}
	void unionp(int a, int b) {
		int pa = findp(a);
		int pb = findp(b);
		if (pa != pb) {
			father[pb] = pa;
			count--;
		}
	}
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		if (n == 0) return 0;
		count = n;
		father.resize(n);
		for (int i = 0; i < n; i++) {
			father[i] = i;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++)
				if (M[i][j] == 1) {
					unionp(i, j);
				}
		}
		return count;
	}
};
class Solution_leet100 {
public:
	int findCircleNum(vector<vector<int>>& M) {
		if (M.empty())return 0;
		int m = (int)M.size();
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			if (M[i][i] == -1)continue;
			dfs(M, i);
			++cnt;
		}
		return cnt;
	}

	void dfs(vector<vector<int>> &M, int i) {
		queue<int> q;
		q.push(i);
		M[i][i] = -1;
		while (!q.empty()) {
			int node = q.front(); q.pop();
			for (int next = 0; next < (int)M[node].size(); ++next) {
				if (M[node][next] == 0 || M[next][next] == -1)continue;
				M[next][next] = -1;
				q.push(next);
			}
		}
	}
};

int main() {
	Solution a;
	vector<vector<int>> num{ { 1,0,0,1 },{ 0,1,1,0 },{ 0,1,1,1 },{ 1,0,1,1 } };
	a.findCircleNum(num);
	return 0;
}
