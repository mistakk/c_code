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
	TreeNode * deleteNode(TreeNode* root, int key) {
		if (root == NULL)
			return nullptr;
		if (root->val == key) {
			if (root->right == NULL) {
				TreeNode * left = root->left;
				delete root;
				return left;
			}
			else {
				TreeNode * right = root->right;
				while (right->left) {
					right = right->left;
				}
				swap(root->val, right->val);
			}
		}
		root->left = deleteNode(root->left, key);
		root->right = deleteNode(root->right, key);
		return root;
	}

	TreeNode * deleteNode2(TreeNode *root, int key) {
		if (root == NULL)
			return nullptr;
		if (root->val == key) {
			if (root->right == NULL) {
				TreeNode *left = root->left;
				delete root;
				return left;
			}
			else {
				TreeNode * right = root->right;
				while (right->left) {
					right = right->left;
				}
				right->left = root->left;
				right = root->right;
				delete root;
				return right;
			}
		}
		if (root->val > key && root->left != NULL)
			return deleteNode(root->left, key);
		else if (root->val < key && root->right != NULL)
			return deleteNode(root->right, key);
		return root;
	}
};



void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;

	vector<int> ret2{ 1, 2, 2, 4 };
	vector<int>  ret = a.findErrorNums(ret2);
	show(ret);
}