using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int cnt = 0;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (i == 0 && j == 0 && board[i][j] == 'X')
					cnt += 1;
				else if (i == 0 && j != 0 && board[i][j] == 'X' && board[i][j - 1] != 'X')
					cnt += 1;
				else if (i != 0 && j == 0 && board[i][j] == 'X' && board[i - 1][j] != 'X')
					cnt += 1;
				else if (i != 0 && j != 0 && board[i][j] == 'X' && board[i][j - 1] != 'X' &&board[i - 1][j] != 'X')
					cnt += 1;
		return cnt;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	string s = "123456789123456789";
	x = [["X", ".", ".", "X"], [".", ".", ".", "X"], [".", ".", ".", "X"]];
	printf("s\n", s);
	cout << "checkbad letter" << endl;

}