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



//16.25
class Solution {
public:
	int longestMountain(vector<int>& A) {
		int flag = -1, maxval = 0, nowval = 0;
		if (A.size() <= 2)
			return 0;
		for (int i = 1; i < A.size(); i++) {
			if (A[i] > A[i - 1]) {
				if (flag == -1 || flag ==1)
					nowval = 1;
				nowval++;
				flag = 0;
			}
			else if (A[i] == A[i - 1]) {
				nowval = 0;
				flag = -1;
			}
			else if (A[i] < A[i - 1]) {
				if (flag == 0 || flag == 1) {
					nowval++;
					maxval = max(maxval, nowval);
					flag = 1;
				}
			}
		}
		if (maxval == 0)
			return 0;
		else
			return maxval + 1;
	}
};

int main() {
	Solution a;
	return 0;
}