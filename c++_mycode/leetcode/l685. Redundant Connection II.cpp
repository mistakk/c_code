

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

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> parent(2001);
		for (int i = 0; i < 2001; ++i)
			parent[i] = i;
		for (auto edge : edges) {
			int a = edge[0];
			int b = edge[1];
			if (findparent(parent, a) != findparent(parent, b))
				parent[findparent(parent, b)] = findparent(parent, a);
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
};





void main()
{

	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<vector<int>>mp{ vector<int>{1, 2}, vector<int>{2, 3}, vector<int>{3, 4}, vector<int>{4, 1} };
	vector<int> haha = a.findRedundantConnection2(mp);
	show(haha);

}