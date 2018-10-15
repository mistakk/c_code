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

//N will be an integer in the range[1, 500].
//mines will have length at most 5000.
//mines[i] will be length 2 and consist of integers in the range[0, N - 1].
//(Additionally, programs submitted in C, C++, or C# will be judged with a slightly smaller time limit.)


class Solution {
public:
	int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {

	}
};

int main() {
	Solution a;
	vector<vector<int>>mines;
	vector<int> d{ 0,3 };
	vector<int> d2{ 0,9 };
	mines.push_back(d);
	mines.push_back(d2);
	a.orderOfLargestPlusSign(15, mines);
	return 0;
}