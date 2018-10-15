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
	int binsearch(vector<int>num, int target, int start, int end) {
		if (num.size()==0 || num[start] > target)
			return -1;
		while (start <= end) {
			if (target >= num[end])
				return end;
			int mid = (start + end) / 2;
			if (target < num[mid])
				end = mid - 1;
			else if (target < num[mid + 1] && num[mid] <= target)
				return mid;
			else
				start = mid + 1;
		}
	}
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		//find row
		if (matrix.size() == 0 || matrix[0].size() == 0 || matrix[0][0] > target)
			return false;
		vector<int>vec1;
		for (int i = 0; i < matrix.size(); i++)
			vec1.push_back(matrix[i][0]);
		int row = binsearch(vec1, target, 0, matrix.size()-1);
		int col = binsearch(matrix[row], target, 0, matrix[0].size()-1);
		cout << row << endl;
		cout << col<< endl;

		if (matrix[row][col] != target)
			return false;
		else
			return true;
	}
};


int main() {
	Solution a;
	int n = 10;
	int m = 10;
	vector<int>mm{ 1,3,5,7,9,11 };
	for (int i = 0; i < 15; i++)
		cout << a.binsearch(mm, i, 0, 5) << endl;
	return 0;

	vector<vector<int>> vec(m, vector<int>(n, 0));// {1, 3, 5, 7, 9, 14};
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			vec[i][j] = i * 100 + j * 10;
	cout << a.searchMatrix(vec,110) << endl;;

	return 0;
} 