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
	void gameOfLife(vector<vector<int>>& board) {
		//5.21
		vector<int>row{ -1,-1,-1,0,0,1,1,1 };
		vector<int>col{ -1,0,1,-1,1,-1,0,1 };
		int n = board.size(), m = board[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					if (i + row[k] >= 0 && i + row[k] < n && j + col[k] >= 0 && j + col[k] < m)
						cnt += (board[i + row[k]][j + col[k]] & 1);
				}
				if ((board[i][j] &1) && (cnt == 2 || cnt == 3)) {
					board[i][j] |= 2;
				}
				else if ((!(board[i][j] & 1)) && cnt == 3) {
					board[i][j] |= 2;
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				board[i][j] >>= 1;
	}
};
//[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
int main() {
	Solution a;
	vector<vector<int>>num{ { 0, 1, 0 },{ 0, 0, 1 },{ 1, 1, 1 },{ 0, 0, 0 }, };
	a.gameOfLife(num);
	return 0;
}
