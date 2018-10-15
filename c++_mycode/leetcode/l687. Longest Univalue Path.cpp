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
	int longestUnivaluePath(TreeNode* root) {
		int history= 0;
		if (!root)
			longest(root, history);
		return history;
	}
	static int longest(TreeNode* root, int &history) {
		int l = (root->left == NULL) ? 0 : longest(root->left, history);
		int r = (root->right == NULL) ? 0 : longest(root->right, history);
		int resl = (root->left != NULL && root->val == root->left->val) ? l + 1 : 0;
		int resr = (root->right != NULL && root->val == root->right->val) ? r + 1 : 0;
		history = max(history, resl + resr);
		return max(resl, resr);
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