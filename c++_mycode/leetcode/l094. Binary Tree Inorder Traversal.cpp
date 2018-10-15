
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



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<int> inorderTraversal2(TreeNode* root) {
		vector<int>vec;
		if (!root)
			return vec;
		stack<TreeNode*>sk;
		sk.push(root);
		TreeNode *now, *left, *right;
		while (!sk.empty()) {
			now = sk.top(), sk.pop();
			left = now->left;
			right= now->right;
			if (left == NULL && right == NULL) {
				vec.push_back(now->val);
				continue;
			}
			now->left = NULL;
			now->right = NULL;

			if (right)
				sk.push(right);

			sk.push(now);

			if(left)
				sk.push(left);

		}
		return vec;
	}
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int>vec;
		helper1(root, vec);
		return vec;
	}
	void helper1(TreeNode* root, vector<int> &vec) {
		if (root == NULL)
			return;
		helper1(root->left, vec);
		vec.push_back(root->val);
		helper1(root->right, vec);
	}
};

int main() {
	Solution a;
	TreeNode *t1 = new TreeNode(1);
	TreeNode *t2 = new TreeNode(2);
	TreeNode *t3 = new TreeNode(3);
	t1->left = NULL;
	t1->right= t2;
	t2->left= t3;
	vector<int>vec = a.inorderTraversal(t1);
	for (auto i : vec) {
		cout << i << endl;
	}
	return 0;
}


