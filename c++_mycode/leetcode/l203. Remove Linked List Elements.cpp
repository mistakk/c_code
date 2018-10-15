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
	ListNode * reverse(ListNode* head) {
		if (!head)
			return NULL;
		ListNode* prev = NULL, *next = NULL;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
	}
	bool ifCircle(ListNode *head) {
		if (!(head&&head->next))
			return false;
		ListNode*slow = head, *fast = head;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
				return true;
		}
		return false;
	}

	int sizeCircle(ListNode*head) {
		if (!(head&&head->next))
			return 0;
		ListNode*slow = head, *fast = head;
		int cirsize = 1;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				// slow is the begining
				while (slow->next != fast) {
					cirsize += 1;
					slow = slow->next;
				}
				return cirsize;
			}
		}
		return 0;
	}

	ListNode* findCircleIn(ListNode* head) {
		if (!(head&&head->next))
			return NULL;
		ListNode*slow = head, *fast = head;
		while (fast&&fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				fast = head;
				while (slow != fast) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return NULL;
	}

	int Listsize(ListNode* head) {
		int size = sizeCircle(head);
		if (size == 0) {
			// no circle
			ListNode*slow = head;
			while (slow != NULL) {
				slow = slow->next;
				size += 1;
			}
		}
		else {
			// has circle
			size = sizeCircle(head);
			ListNode *firstcircle = findCircleIn(head);
			ListNode * slow = head;
			while (slow != firstcircle) {
				size += 1;
				slow = slow->next;
			}
		}
		return size;
	}

	ListNode* createListNode(vector<int> data) {
		if (data.size() == 0)
			return NULL;
		ListNode* head = new ListNode(data[0]);
		ListNode *tail = head;
		for (int i = 1; i < data.size(); ++i) {
			ListNode *temp = new ListNode(data[i]);
			tail->next = temp;
			tail = tail->next;
		}
		return head;
	}

	void showListNode(ListNode*head) {
		if (!head)
			cout << "ListNode head is NULL" << endl;
		int cnt = 0;
		if (ifCircle(head)) {
			// contain circle 
			cout << "ListNode contain circle" << endl;
			ListNode *firstcircle = findCircleIn(head);
			ListNode *slow = head;
			while (slow != firstcircle) {
				cout << slow->val << " ";
				slow = slow->next;
				cnt++;
				if (cnt > 10) {
					cout << "first loop error";
					return;
				}
			}
			slow = firstcircle->next;
			cout << "( " << firstcircle->val << " ";
			while (slow != firstcircle) {
				cout << slow->val << " ";
				slow = slow->next;

				cnt++;
				if (cnt > 20) {
					cout << "second loop error";
					return;
				}
			}
			cout << ")";
			return;
		}
		while (head) {
			cout << head->val << "  ";
			head = head->next;
			cnt++;
			if (cnt > 30) {
				cout << "third loop error";
				return;
			}
		}
		cout << endl;
	}
	ListNode* removeElements(ListNode* head, int val) {
		while (head) {
			if (head->val == val)
				head = head->next;
			else {
				break;
			}
		}
		ListNode *ret = head;
		if (!head)
			return head;
		while (head->next) {
			if (head->next->val == val)
				head->next = head->next->next;
			else
				head = head->next;
		}
		return ret;
	}

};

void main()
{
	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<int>data{ 1,1,2,4,5 };
	ListNode *head = a.createListNode(data);
	a.showListNode(head);
	head = a.removeElements(head, 1);
	a.showListNode(head);

}