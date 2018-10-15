using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		int ret = 0;
		bool before = false;
		while (head != NULL) {
			int val = head->val;
			bool exist = (find(G.begin(), G.end(), val) != G.end()); 
			if (exist == false) {
				if (before == true) {
					ret += 1;
					before = false;
				}
			}
			else {
				if (before == false) {
					before = true;
				}
			}
			head = head->next;
		}
		return ret + before;
	}
};

int main() {
	Solution a;
	return 0;
}