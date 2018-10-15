using namespace std;
#include <algorithm>
#include <vector>
#include <iostream>

int dp(int time, vector<int>stone) {
	time -= 1;
	vector< vector<int>> c;
	int num = stone.size();
	c.resize(num);
	for (int i = 0; i < c.size(); i++) {
		c[i].resize(time + 1);
	}
	for (int i = 0; i < num; i++)
		c[i][0] = 0;
	for (int i = 1; i <= time; i++) {	//time xiaoming get
		for (int j = 0; j < num; j++) {	//stone he can load
			if (j == 0) {				//the first stone
				if (i < stone[j])
					c[j][i] = 0;
				else
					c[j][i] = stone[j];
			}
			else {
				if (i >= stone[j] && c[j - 1][i - stone[j]] + stone[j] > c[j - 1][i])
					c[j][i] = c[j - 1][i - stone[j]] + stone[j];
				else
					c[j][i] = c[j - 1][i];
			}
		}
	}
	vector<int> choose(num, 0);
	int time_now = time;
	for (int j = num - 1; j >= 0; j--) {	//stone he can load
		if (j != 0) {
			if (c[j][time_now] == c[j - 1][time_now])
				;
			else {
				choose[j] = 1;
				time_now -= stone[j];
			}
		}
		else {
			if (c[j][time_now] > 0)
				choose[j] = 1;
		}
	}
	cout <<"_____________"<<endl;
	int ret_time = 0;
	int max_notchoose = 0;
	for (int j = num - 1; j >= 0; j--) {	//stone he can load
		cout << choose[j] << "       ";
		if (choose[j] == 1)
			ret_time += stone[j];
		else
			max_notchoose = max(max_notchoose, stone[j]);
	}
	cout << endl;

	return max_notchoose + ret_time;
}


int main() {
	std::vector<int>stone{ 5,5,5 };
	int time = 11;
	cout << dp(time, stone);
}









