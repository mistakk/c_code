using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
void show(vector<vector<int>> hehe) {
	for (int i = 0; i != hehe.size(); i++) {
		for (int j = 0; j < hehe[0].size(); j++) {
			cout << hehe[i][j] << " ";
		}
	    cout << endl;
	}
}

class Solution {
public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
		queue<int> q;
		int n = matrix.size();
		int m = matrix[0].size();
		vector<vector<int>> flag(n, vector<int>(m, 0));
		int now_i, now_j;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				if (matrix[i][j] == 0) {
					q.push(i*10001+j);
					flag[i][j] = 1;
				}
		}
		while (!q.empty()) {
			now_i = q.front();
			now_j = now_i % 10001;
			now_i = now_i / 10001;
			q.pop();
				
			if (now_i - 1 >= 0 && flag[now_i - 1][now_j] == 0) {
				matrix[now_i - 1][now_j] = 1 + matrix[now_i][now_j];
				q.push((now_i - 1) * 10001 + now_j);
				flag[(now_i - 1)][now_j] = 1;
			}
			if (now_i + 1 < n && flag[now_i + 1][now_j] == 0){
				matrix[now_i + 1][now_j] = 1 + matrix[now_i][now_j];
				q.push((now_i + 1) * 10001 + now_j);
				flag[(now_i + 1)][now_j] = 1;
			}
			if (now_j - 1 >= 0 && flag[now_i][now_j - 1] == 0){
				matrix[now_i][now_j - 1] = 1 + matrix[now_i][now_j];
				q.push((now_i) * 10001 + now_j - 1);
				flag[(now_i)][now_j - 1] = 1;
			}
			if (now_j + 1 < m && flag[now_i][now_j + 1] == 0){
				matrix[now_i][now_j + 1] = 1 + matrix[now_i][now_j]; 
				q.push((now_i) * 10001 + now_j + 1);
				flag[(now_i)][now_j + 1] = 1;
			}
		}
		return matrix;
	}
};
void main()
{
	vector<vector<int>>matrix(5,vector<int>(5,1));
	matrix[2][2] = 0;
	matrix[2][1] = 0;
	show(matrix);
	cout << endl;
	cout << endl;
	Solution a;
	matrix = a.updateMatrix(matrix);
	show(matrix);

}