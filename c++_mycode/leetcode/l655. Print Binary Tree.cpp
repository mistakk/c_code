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
	vector<vector<string>> printTree2(TreeNode* root) {
		vector<vector<string>> result;
		queue<pair<int, TreeNode*>>q;
		vector<vector<pair<int, int>>> store;
		if (!root)
			return result;
		pair<int, TreeNode*> p(1, root);
		q.push(p);
		store.push_back(vector<pair<int, int>>());
		store[0].push_back(pair<int, int>(1, root->val));
		int depth = 0;
		while (!q.empty()) {
			pair<int, TreeNode*> p = q.front();
			int cnt = q.size();
			store.push_back(vector<pair<int, int>>());
			depth += 1;
			while (cnt--) {
				p = q.front();
				q.pop();
				if (p.second->left) {
					pair<int, TreeNode*> pl(p.first * 2, p.second->left);
					q.push(pl);
					store[depth].push_back(pair<int, int>(p.first * 2, p.second->left->val));
				}
				if (p.second->right) {
					pair<int, TreeNode*> pl(p.first * 2 + 1, p.second->right);
					store[depth].push_back(pair<int, int>(p.first * 2 + 1, p.second->right->val));
					q.push(pl);
				}
			}
		}
		int width = pow(2, depth) - 1;
		for (int d_now = 1; d_now <= depth; d_now++) {
			result.push_back(vector<string>(width, ""));
			int gap = pow(2, depth - d_now + 1);
			int first_key_pos = pow(2, depth - d_now) - 1;
			int first_key_val = pow(2, d_now-1);
			for (int i = 0; i < store[d_now - 1].size(); i++) {
				int key = store[d_now - 1][i].first;
				string value = to_string(store[d_now - 1][i].second);
				int pos = (key - first_key_val)*gap + first_key_pos; //d_now, d, key
				result[d_now - 1][pos] = value;
			}
		}
		return result;
	}
	vector<vector<string>> printTree(TreeNode* root) {
		if (!root)
			return vector<vector<string>>();
		int h = get_height(root);
		int w = get_width(root);
		vector<vector<string>> result(h, vector<string>(w, ""));
		helper(root, result, 0, 0, w);
		return result;
	}
	int get_height(TreeNode* root) {
		if (!root)
			return 0;
		int l = get_height(root->left);
		int r = get_height(root->right);
		return max(l, r) + 1;
	}
	int get_width(TreeNode* root) {
		if (!root)
			return 0;
		int l = get_width(root->left);
		int r = get_width(root->right);
		return max(l, r) * 2 + 1;
	}

	void helper(TreeNode *root, vector<vector<string>> &result, int level, int left, int right) {
		if (!root)
			return;
		int mid = left + (right- left) / 2;
		result[level][mid] = to_string(root->val);
		helper(root->left, result, level + 1, left, mid - 1);
		helper(root->right, result, level + 1, mid + 1, right);
	}
};
void main()
{
	Solution a;
	TreeNode *root = new  TreeNode(1);
	TreeNode *l = new  TreeNode(2);
	TreeNode *r = new  TreeNode(3);
	TreeNode *ll = new  TreeNode(4);
	l->left = ll;
	root->left = l;
	root->right = r;
	vector<vector<string>> result = a.printTree2(root);
	cout << result.size() << endl;
	cout << result[0].size() << endl;
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[0].size(); j++)
			cout << result[i][j] << "  ";
		cout << endl;
	}

}