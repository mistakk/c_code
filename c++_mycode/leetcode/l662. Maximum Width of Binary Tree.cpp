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
	int widthOfBinaryTree(TreeNode* root) {
		queue<pair<int, TreeNode*>>q;
		if (!root)
			return 0;
		pair<int, TreeNode*> p(0, root);
		q.push(p);
		int max_width = 0;
		while (!q.empty()) {
			pair<int, TreeNode*> p = q.front();
			int min_val = p.first;
			int cnt = q.size();
			while (cnt--) {
				p = q.front();
				q.pop();
				if (p.second->left) {
					pair<int, TreeNode*> pl(p.first * 2, p.second->left);
					q.push(pl);
				}
				if (p.second->right) {
					pair<int, TreeNode*> pl(p.first * 2+1, p.second->right);
					q.push(pl);
				}
			}
			int max_val = p.first;
			max_width = max(max_width, max_val - min_val + 1);
		}
		return max_width;
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