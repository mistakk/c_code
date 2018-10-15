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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ret;
		queue<TreeNode *> q;
		if (root == nullptr)
			return ret; 
		q.push(root);
		while (!q.empty()) {
			int cnt = q.size();
			int size = cnt;
			double sum = 0;
			while (cnt) {
				TreeNode *now = q.front();
				q.pop();
				sum += now->val;
				cnt--;
				if (now->left != nullptr)
					q.push(now->left);
				if (now->right != nullptr)
					q.push(now->right);
			}
			ret.push_back(sum / size);
		}
		return ret;
	}
	static void dfs(TreeNode* root, vector<double> ret) {
		if (root == nullptr)
			return;


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
}