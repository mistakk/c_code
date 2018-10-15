using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	bool isToeplitzMatrix(vector<vector<int>>& matrix) {
		int n = matrix.size();
		if (n <= 1)
			return true;
		int m = matrix[0].size();
		if (m <= 1)
			return true;
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++)
				if (matrix[i][j] != matrix[i - 1][j - 1])
					return false;
		}
		return true;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<vector<int>> times;
	times.push_back(vector<int>{2, 1, 1});
	times.push_back(vector<int>{2, 3, 1});
	times.push_back(vector<int>{3, 4, 111});

	cout << "sys start!" << endl;
	vector<int> te{ 5,1 };


}