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



class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int n = arr.size();
		int far = -1, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (((arr[i] == i) && (i > far)) || (arr[i] < i && i == far))
				cnt++;
			else if ((arr[i] > i) && (arr[i] > far))
				far = arr[i];
		}
		return cnt;
	}
};
int main() {
	Solution a;
	vector<int> arr{ 0,2,3,1,4};
	cout << a.maxChunksToSorted(arr) << endl;
	return 0;
}
