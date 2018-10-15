

using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
void show(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}

class Solutiona {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		vector<bool> visited(n, false);
		vector<vector<bool>> graph;
		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i][0];
			int b = edges[i][1];
			graph[a][b] = true;
			graph[b][a] = true;
		}
	}
	vector<int> findRedundantConnection2(vector<vector<int>>& edges) {
		vector<int> parent(2001);
		for (int i = 0; i < 2001; ++i)
			parent[i] = i;
		for (auto edge : edges) {
			int a = edge[0];
			int b = edge[1];
			if (findparent(parent, a) != findparent(parent, b))
				parent[findparent(parent, a)] = findparent(parent, b);
			else {
				return edge;
			}
		}
		return vector<int>();
	}
	int findparent(vector<int> parent, int p) {
		if (parent[p] != p)
			parent[p] = findparent(parent, parent[p]);
		return parent[p];
	}
	static void dfs(vector<vector<int>>& edges, vector<bool> visited)
	{
		queue<int> q;
		visited[edges[0][0]] = true;
		visited[edges[0][0]] = true;
		q.push(edges[0][1]);
		while (!q.empty()) {

		}
	}
};




class Solution {
public:
	vector<int>father;
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		father.resize(2002);
		int pa, pb;
		for (int i = 0; i < father.size(); i++)
			father[i] = i;
		for (auto edge : edges) {
			pa = findparent(edge[0]);
			pb = findparent(edge[1]);
			if (pa == pb) {
				cout << edge[0] << " " << edge[1] << endl;
				return edge;
			}
			else
				father[pb] = pa;
		}
	}
	int findparent(int x) {
		if (x != father[x])
			father[x] = findparent(father[x]);
		return father[x];
	}
};

void main() {
	Solution a;
	vector<vector<int>>edges;
	edges.push_back({ 1, 4 });
	edges.push_back({ 3,4 });
	edges.push_back({ 1, 3 });
	edges.push_back({ 1, 2 });
	edges.push_back({ 4, 5 });
	a.findRedundantConnection(edges);
}