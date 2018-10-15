using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
int findf(vector<int> &father, int x) {
	if (father[x] != x)
		father[x] = findf(father, father[x]);
	return father[x];
}
void unionp(vector<int> &father, int a, int b) {
	int pa = findf(father, a);
	int pb = findf(father, b);
	if (pa != pb) {
		father[pb] = pa;
	}
}

int main()
{
	int n, m;
	n = 10, m = 10;
	vector<vector<int>>num
	{ {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
		{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
		{ 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
		{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
		{ 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
		{ 0, 0, 0, 1, 0, 1, 0, 0, 0, 0},
		{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0} };
	vector<int> father(m*n , 0);
	vector<int> di{ -1,-1,-1,0,0,1,1,1 };
	vector<int> dj{ -1,0,1,-1,1,-1,0,1 };

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			father[i*m + j] = i * m + j;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (num[i][j] != 1)
				continue;
			for (int k = 0; k < 8; k++) {
				int newi = i + di[k];
				int newj = j + dj[k];
				if ((newi >= 0) && (newi < n) && (newj >= 0) && (newj < m) && (num[newi][newj] == 1)) {
					unionp(father, i*m + j, newi*m + newj);
				}
			}
		}
	map<int, int> mpall;
	int maxval = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (num[i][j] != 1)
				continue;
			int idx = i * m + j;
			int p = findf(father, father[idx]);
			mpall[p] += 1;
			maxval = max(maxval, mpall[p]);
		}
	cout << mpall.size() << "," << maxval << endl;
}