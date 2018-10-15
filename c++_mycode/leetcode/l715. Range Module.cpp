using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>



class RangeModule {
public:
	vector<pair<int, int>>num;

	void addRange(int left, int right) {
		
	}

	bool queryRange(int left, int right) {
		for (int i = 0; i < num.size(); i++) {
			if (left > num[i].second) {
				continue;
			}
			else {
				if (left == num[i].second) {
					//search right and the next 
				}
			}
		}
	}

	void removeRange(int left, int right) {

	}
};

/**
* Your RangeModule object will be instantiated and called as such:
* RangeModule obj = new RangeModule();
* obj.addRange(left,right);
* bool param_2 = obj.queryRange(left,right);
* obj.removeRange(left,right);
*/

int main() {
	RangeModule obj;//
	int left = 10, right = 11;
	obj.addRange(left, right);
	bool param_2 = obj.queryRange(left, right);
	obj.removeRange(left, right);
	return 0;
}