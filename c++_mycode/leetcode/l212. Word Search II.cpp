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
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	}
	bool searchoneword(vector<vector<char>>& board, string words) {
		map<char, vector<pair<int, int>>>point_mp;
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++) {
				point_mp[board[i][j]].push_back(make_pair(i, j));
			}
		for (int i = 0; i < words.size(); i++)
			if (point_mp[words[i]].size() == 0)
				return false;
		unordered_set<pair<int, int>>visited;
		stack<pair<int, int>>q;
		for (int i = 0; i < point_mp[words[0]].size(); i++) {
			q.push(point_mp[words[0]][i]);
		}
		int now = 0;
		while (now != words.size()) {
			int cnt = q.size();
			while (cnt--) {
				pair<int, int> first = q.top();
				visited.insert(first);
				q.pop();
				for (int i = 0; i < point_mp[words[now]].size(); i++) {
					q.push(point_mp[words[now]][i]);
				}

			}
		}
	}
	bool bfs(vector<vector<char>>& board, string target) {
		if (target.size() == 0)
			return true;
		stack<pair<int, int>>sk;
		int row_max = board.size();
		int col_max = board[0].size();
		for (int i = 0; i < row_max; i++) {
			for (int j = 0; j < col_max; j++) {
				if (board[i][j] == target[0])
					sk.push(make_pair(i, j));
			}
		}
		pair<int, int>node;
		set<pair<int, int>>visited;
		int cnt = 1;
		while (!sk.empty() || cnt == target.size()) {
			node = sk.top(), sk.pop();
			int row = node.first, col = node.second;
			visited.insert(node);
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++) {
					if (row + 2 * i - 1 >= 0 && row + 2 * i - 1 < row_max && col + 2 * j - 1 >= 0 && col + 2 * j - 1 < col_max &&board[row + 2 * i - 1][row + 2 * i - 1] == target[cnt]) {
						pair<int, int> node_new = make_pair(row + 2 * i - 1, row + 2 * i - 1);
						if (visited.find(node_new) == visited.end())
							sk.push(node_new);
					}
				}




		}
	}
};





int main() {
	Solution a;
	return 0;
}
