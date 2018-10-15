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
	TreeNode * constructMaximumBinaryTree(vector<int>& nums) {
		if (nums.size() == 0)
			return nullptr;
		int maxidx = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] > nums[maxidx])
				maxidx = i;
		}
		TreeNode *root = new TreeNode(nums[maxidx]);
		std::vector<int> left(nums.begin(), nums.begin() + maxidx);
		std::vector<int> right(nums.begin() + maxidx, nums.end());
		root->left = constructMaximumBinaryTree(left);
		root->right = constructMaximumBinaryTree(right);
		return root;
	}
};

void main()
{
	Solution a;
	std::vector<int> originalVector{ 1,2,3,4 };
	int idx = 3;
	std::vector<int> subList(originalVector.begin(), originalVector.begin());
	std::vector<int> subList2(originalVector.begin()+idx+1, originalVector.end());
	show(subList);
	show(subList2);
}