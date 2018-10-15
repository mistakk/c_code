using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int sum = 0, avg = 0, n = machines.size(), cnt = 0, ret = 0;
		for (int i = 0; i < n; i++) {
			sum += machines[i];
		}
		if (sum%n != 0)
			return -1;
		avg = sum / n;
		for (int i = 0; i < n; i++) {
			int val = machines[i] - avg;
			cnt += val;
			ret = max(abs(cnt), max(ret, val));
		}
		return ret;
	}
};
void main()
{


}