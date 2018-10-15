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
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
void show(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}

struct TreeNode {
	int value;
	struct TreeNode * left, *right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *l1 = headA, *l2 = headB;
		while (l1 != l2) {
			l1 = l1 != NULL ? l1->next : headB;
			l2 = l2 != NULL ? l2->next : headA;
		}
		return l1;
	}
};

void main()
{
	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<int>data{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector<int>data2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

	ListNode *headA = a.createListNode(data);
	ListNode *headB = a.createListNode(data2);
	ListNode *r = a.getIntersectionNode(headA, headB);
	a.showListNode(headB);
	a.showListNode(headA);
	a.showListNode(r);
}