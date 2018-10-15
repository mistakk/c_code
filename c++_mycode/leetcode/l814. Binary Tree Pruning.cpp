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
	TreeNode * pruneTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		else {
			root->left = pruneTree(root->left);
			root->right = pruneTree(root->right);
			if (root->val == 0 && (root->left == NULL) && (root->right == NULL))
				return NULL;
			else
				return root;
		}
	}
};

int main() {
	Solution a;
	TreeNode* aa = new TreeNode(1);
	TreeNode* a1 = new TreeNode(0);
	TreeNode* a2 = new TreeNode(0);
	TreeNode* a3 = new TreeNode(1);
	aa->right = a1;
	a1->left = a2;
	a1->right = a3;
	a.pruneTree(aa);
	return 0;
}



