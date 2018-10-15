using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
void show(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}

struct TreeNode {
	int value;
	struct TreeNode * left, *right;
	TreeNode(int x) : value(x), left(NULL), right(NULL) {}
};
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	int movesToChessboard(vector<vector<int>>& board) {
		int n = board.size(), rowsum = 0, colsum = 0, rowswap = 0, colswap = 0, i, j;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				if (board[i][0] ^ board[j][0] ^ board[0][j] ^ board[0][i])
					return -1;
			}
		for (i = 0; i < n; i++) {
			rowsum += board[0][i];
			colsum += board[i][0];
			rowswap += board[0][i] == i % 2;
			colswap += board[i][0] == i % 2;
		}
		if (rowsum > (n + 1) / 2 || rowsum < n / 2)
			return -1;
		if (colsum > (n + 1) / 2 || colsum < n / 2)
			return -1;
		if (n % 2) {
			if (rowsum % 2)
				rowswap = n - rowswap;
			if (colswap % 2)
				colswap = n - colswap;
		}
		else {
			colswap = min(n - colswap, colswap);
			rowswap = min(n - rowswap, rowswap);
		}
		return (colswap + rowswap)/2;
	}
};







void main()
{

	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	vector<int>mp{ 1,3,2,4,5 };

	int ret = a.monotoneIncreasingDigits(1234);
	cout << ret << endl;

}