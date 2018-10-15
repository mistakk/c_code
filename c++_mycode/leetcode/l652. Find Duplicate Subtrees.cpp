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
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		vector<TreeNode *> ret;
		std::map<string, int>mp;
		serialize(root, mp, ret);
		return ret;
	}
	string serialize(TreeNode* root, std::map<string, int> &mp, vector<TreeNode*> &ret) {
		if (!root)
			return "#";
		string s = to_string(root->val) + "," + serialize(root->left, mp, ret) + "," + serialize(root->right, mp, ret);
		if (mp[s] == 1) 
			ret.push_back(root);
		mp[s] += 1;
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