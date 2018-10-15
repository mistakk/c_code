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
	TreeNode * addOneRow(TreeNode* root, int v, int d) {
		if (d == 1) {
			TreeNode *newr = new TreeNode(v);
			newr->left = root;
			return newr;
		}
		d -= 2;
		queue<TreeNode*>q;
		q.push(root);
		while (d--) {
			int cnt = q.size();
			while (cnt--) {
				TreeNode* p = q.front();
				q.pop();
				if (p->left != nullptr)
					q.push(p->left);
				if (p->right!=nullptr)
					q.push(p->right);
			}
		}
		while (!q.empty()) {
			TreeNode *p = q.front();
			q.pop();
			if (p->left != nullptr) {
				TreeNode *l = new  TreeNode(v);
				l->left = p->left->left;
				l->right = p->left->right;
				p->left = l;
			}
			if (p->right!= nullptr) {
				TreeNode *r = new  TreeNode(v);
				r->left = p->right->left;
				r->right = p->right->right;
				p->right= r;
			}
		}
		return root;
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