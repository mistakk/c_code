using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>



void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int networkDelayTime2(vector<vector<int>>& times, int N, int K) {
		int sum_val = 0, past_val = 0, cur_index = K-1, next_index, i;
		vector<vector<int>> g;
		g.resize(N);
		for (i = 0; i < N; i++)
			g[i] = vector<int>(N, -1);
		for (i = 0; i < times.size(); i++) {
			g[times[i][0]-1][times[i][1]-1] = times[i][2];
		}
		vector<int> num(N + 1, -1);
		num[N] = INT_MAX;
		num[K-1] = 0;
		if (cur_index != N) {
			next_index = N;
			for (int i = 0; i < N; i++) {
				if (g[cur_index][i] > 0 && num[i] != 0) {
					if (num[i] < 0)
						num[i] = g[cur_index][i];
					else 
						num[i] = min(num[i] - past_val, g[cur_index][i]);
					
					if (num[next_index] > num[i])
						next_index = i;
				}
			}
			past_val = g[cur_index][next_index];
			sum_val += past_val;
			cur_index = next_index;
		}
		for (i = 0; i < N; i++)
			if (num[i] != 0)
				return -1;
		return sum_val;
	}
	int networkDelayTime(vector<vector<int>>& times, int N, int K) {
		vector<int> waits(N + 1, INT_MAX);
		map<int, map<int, int>> adj;
		for (auto e : times)
			adj[e[0]][e[1]] = e[2];
		queue<int> q;
		q.push(K);
		waits[K] = 0;
		while (!q.empty()) {
			set<int> set;
			for (int i = q.size(); i > 0; i--) {
				int u = q.front();
				q.pop();
				for (pair<int, int> nb : adj[u]) {
					int v = nb.first;
					if (waits[u] + adj[u][v] < waits[v]) {
						if (!set.count(v)) {
							set.insert(v);
							q.push(v);
						}
						waits[v] = waits[u] + adj[u][v];
					}
				}
			}
		}
		int maxwait = 0;
		for (int i = 1; i <= N; i++)
			maxwait = max(maxwait, waits[i]);
		return maxwait == INT_MAX ? -1 : maxwait;
	}

};
void main()
{

	cout << "checkbad letter" << endl;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2,1,1});
	times.push_back(vector<int>{2,3,1});
	times.push_back(vector<int>{3,4,111});
	int N = 4, k = 2; //[[2, 1, 1], [2, 3, 1], [3, 4, 1]]
	cout << a.networkDelayTime(times, N, k);
}