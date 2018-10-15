using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct TreeNode {
	int value;
	struct TreeNode * left, *right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};

//18.20 - 18.26
class Solution {
public:
	int count = 0; 
	int before = -1;
	int find_3(TreeNode *head) {
		if (!head)
			return -1;
		inorder(head);
		if (count == 4)
			return before;
		else
			return -1;
	}
	void inorder(TreeNode *head) {
		if (head->right != NULL && count < 3)
			inorder(head->right);
		
		if ((before > head->value && count < 3) || count == 0)
		{
			count++;
			before = head->value;
		}
		
		if (count == 3)
		{
			before = head->value;
			count++;
		}
		if (head->left != NULL && count < 3)
			inorder(head->left);
	}
};

void main()
{
	Solution a;
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(4);
	TreeNode *n5 = new TreeNode(5);
	TreeNode *n6 = new TreeNode(6);
	TreeNode *n7 = new TreeNode(7);
	n4->right = n5;
	n5->right = n6;
	n4->left = n2;
	n2->left = n1;
	n2->right = n3;
	n6->right= n7;
	
	cout << a.find_3(n4) << endl;

}


