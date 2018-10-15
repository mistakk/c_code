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
	ListNode * sortList(ListNode* head) {
		if (head&&head->next)
			return head;
		ListNode *prev, *slow = head, *fast = head;
		while (fast&&fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;
		head = sortList(head); 
		slow = sortList(slow);
		head = merge(head, slow);
		return head;
	}
	ListNode*merge(ListNode*l1, ListNode*l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode*head, *tail;
		if (l1->val > l2->val) {
			head = l2;
			l2 = l2->next;
		}
		else {
			head = l1;
			l1 = l1->next;
		}
		tail = head;
		while (l1&&l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = NULL;
		if (l1)
			tail->next = l1;
		if (l2)
			tail->next = l2;
		return head;
	}
};





void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<int>mp{ 1,3,2,4,5 };

	int ret = a.monotoneIncreasingDigits(1234);
	cout << ret << endl;

}