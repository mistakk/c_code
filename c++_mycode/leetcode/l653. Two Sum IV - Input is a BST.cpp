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
	bool findTarget2(TreeNode* root, int k) {
		set<int> s;
		return bfs(root, s, k);
	}
	bool bfs(TreeNode* root, set<int> &s, int k) {
		if (!root)
			return false;
		if (s.count(k - root->val) > 0)
			return true;
		s.insert(root->val);
		return (bfs(root->left, s, k) || bfs(root->right, s, k));
	}

	bool findTarget(TreeNode* root, int k) {
		vector<int> nums;
		inorder(root, nums);
		int j = nums.size();
		for (int i = 0; i < j;) {
			if (nums[i] + nums[j] == k)
				return true;
			if (nums[i] + nums[j] < k)
				++i;
			else
				--j;
		}
		return false;
	}
	void inorder(TreeNode* root, vector<int>nums) {
		if (!root)
			return;
		inorder(root->left, nums);
		nums.push_back(root->val);
		inorder(root->right, nums);
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