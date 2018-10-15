using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void show1(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show2(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	bool find_exist_cycle1(TreeNode* s) {
		//bfs
		if (!s)
			return false;
		vector<TreeNode*> visited;
		queue<TreeNode*> q;
		q.push(s);
		while (!q.empty()) {
			int cnt = q.size();
			while (cnt--) {
				TreeNode * temp = q.front();
				q.pop();
				if (find(visited.begin(), visited.end(), temp) != visited.end())
					return true;
				visited.push_back(temp);
				if (temp->left)
					q.push(temp);
				if (temp->right)
					q.push(temp);
			}
		}
		return false;
	}

	bool find_exist_cycle2(TreeNode* s) {
		//dfs
		if (!s)
			return false;
		vector<TreeNode*> visited;
		return dfs1(s, visited);
	}
	bool dfs1(TreeNode* s, vector<TreeNode*> &visited) {
		if (visited.end() != find(visited.begin(), visited.end(), s))
			return true;
		bool l = (s->left != NULL) ? dfs1(s->left, visited) : false;
		bool r = (s->right!= NULL) ? dfs1(s->right, visited) : false;
		return l || r;
	}

	bool find_exist_cycel3(vector<vector<int>> p, int n) {
		//union set  20:47
		vector<bool> white(n, true);
		vector<bool> gary(n, false);
		vector<bool> black(n, false);

		for(int i = 0;i<n;i++){
			if (white[i] == true) {
				if (check_cycle(i, white, gary, black, p))
					return true;
			}
		}
	}
	bool check_cycle(int i, vector<bool> &white, vector<bool> &gary, vector<bool> &black, vector<vector<int>> p) {
		white[i] = false;
		gary[i] = true;
		for (int j = 0; j < p.size(); j++) {
			if (p[i][j] == 1) {
				if (white[i] == true)
					check_cycle(i, white, gary, black, p);
				else if (gary[j] == true)
					return true;
				else
					continue;
			}
		}
		gary[i] = false;
		black[i] = true;
		return false;
	}


};

void main()
{
	Solution a;
	std::vector<int> originalVector{ 1,2,3,4 };
	int idx = 3;
	std::vector<int> subList(originalVector.begin(), originalVector.begin());
	std::vector<int> subList2(originalVector.begin() + idx + 1, originalVector.end());
	show(subList);
	show(subList2);



	TreeNode *r = new  TreeNode(1);
	TreeNode *l = new  TreeNode(2);
	TreeNode *r = new  TreeNode(3);
	TreeNode *ll = new  TreeNode(4);
	l->left = ll;
	r->left = l;
	r->right = r;


}