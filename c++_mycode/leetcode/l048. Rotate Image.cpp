using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size(),temp;
		for (int i = 0; i < n-n/2; i++)
			for (int j = 0; j < n / 2; j++) {
				temp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = temp;
			}
	}
};

void main()
{
	Solution aa;
	vector<int> a = { 1,2,3 };
	vector<int> b = { 4,5,6 };
	vector<int> c = { 7,8,9 };
	vector<vector<int>>  matrix;
	matrix.push_back(a);
	matrix.push_back(b);
	matrix.push_back(c);
	aa.rotate(matrix);
	cout << matrix[0][0] << matrix[0][1] << matrix[1][0] << matrix[1][1] << endl;


}

