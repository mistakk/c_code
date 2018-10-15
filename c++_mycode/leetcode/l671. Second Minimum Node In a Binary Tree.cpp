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
	TreeNode * deserialize(string data) {
		return myderialize(data);
	}
	TreeNode* myderialize(string &data) {
		if (data[0] == '#') {
			if (data.length()>2)
				data = data.substr(2);
			return nullptr;
		}
		int val = getval(data);
		TreeNode *root = new TreeNode(val);
		root->left = myderialize(data);
		root->right = myderialize(data);
		return root;
	}
	static int getval(string& data) {
		int pos = data.find(',');
		int val = stoi(data.substr(0, pos));
		data = data.substr(pos + 1);
		return val;
	}


	int findSecondMinimumValue(TreeNode* root) {
		if (!root) 
			return -1;
		int mi = finddmin(root, root->val);
		return mi;

	}
	static int finddmin(TreeNode* root, int val) {
		if (!root)
			return -1;
		if (root->val != val)
			return root->val;
		int left = finddmin(root->left, val);
		int right= finddmin(root->right, val);
		if (left == -1)
			return right;
		if (right == -1)
			return left;
		return min(left, right);
			
};

void main()
{
	Solution a;
	string s = "2,2,#,#,5,5,#,#,7,#,#";
	TreeNode *root = a.deserialize(s);
	int ss = a.findSecondMinimumValue(root);
	cout << ss << endl;
}