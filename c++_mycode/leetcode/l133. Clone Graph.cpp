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
#include <numeric>


struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
	UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
		if (node == nullptr) {
			return nullptr;
		}
		queue<UndirectedGraphNode *>q1, q2;
		UndirectedGraphNode *temp1, *temp2, *temp;
		UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
		q1.push(node);
		q2.push(root);
		while (!q1.empty()) {
			temp1 = q1.front(); q1.pop();
			temp2 = q2.front(); q2.pop();
			for (auto x : temp1->neighbors) {
				temp = new UndirectedGraphNode(x->label);
				temp2->neighbors.push_back(temp);
				q1.push(x);
				q2.push(temp);
			}
		}
		return root;
	}
};

int main() {
	Solution a;
	return 0;
}
