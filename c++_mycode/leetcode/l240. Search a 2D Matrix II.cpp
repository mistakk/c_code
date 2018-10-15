using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
using namespace std;
#include <vector>

class Solution {
public:
	int bin_search(vector<vector<int>>& matrix, int target, int lineorrowidx, int start, int end, bool lineorrow) {
		while (start <= end) {

		}
		return 1;
	}
	bool bin_search_2d(vector<vector<int>>& matrix, int target, int x0, int x1, int y0, int y1) {
		while (x0 <= x1 && y0 <= y1) {
			if (matrix[x0][y1] == target)
				return false;
			else if (matrix[x0][y1] < target) {
				//search at last row return big idx
				int mid = bin_search(matrix, target, y1, x0, x1, 0);
				if (mid == -1)
					return false;
				x0 = 1;
			}
			else {
				//search at first colume  return small idx
			}
		}



	}
	bool searchMatrix2(vector<vector<int>>& matrix, int target) {
		int x1 = matrix.size();
		int y1 = matrix[0].size();
		if (x1 == 0 || y1 == 0 || target<matrix[0][0] || target> matrix[x1][y1])
			return false;
		return bin_search_2d(matrix, target, 0, x1, 0, y1);
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		int n = matrix[0].size();
		if (m == 0 || n == 0 || target<matrix[0][0] || target> matrix[m-1][n-1])
			return false;
		int i = m - 1;
		int j = 0;
		while (i >= 0 && j <= n - 1) {
			if (matrix[i][j] == target)
				return true;
			else if (matrix[i][j] > target)
				i--;
			else
				j++;
		}
		return false;
	}
};



int main() {


	return 0;
}