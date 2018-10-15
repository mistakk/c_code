#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
	vector<vector<double>> num(16, vector<double>(16, 0));
	vector<vector<double>> dp(16, vector<double>(4, 0));
	//ifstream fin("in.txt"); //打开文件 
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 16; j++) {
			//string nnn;
			//fin >> nnn;
			//num[i][j] = atof(nnn.c_str());
			cin >> num[i][j];
			if (j < 4)
				dp[i][j] = 0;
		}

	for (int i = 0; i < 16; i++) {
		if (i % 2 == 0)
			dp[i][0] = num[i][i + 1];
		else
			dp[i][0] = num[i][i - 1];
	}

	int verse = 1;
	for (int i = 1; i < 4; i++) {
		verse *= 2;
		for (int j = 0; j < 16; j++) {
			cout << j << endl;
			for (int k = 0; k < 16; k++) {
				if (j / (verse * 2) == k / (verse * 2))
					if (j / verse != k / verse)
						dp[j][i] += dp[j][i - 1] * dp[k][i - 1] * num[j][k];
			}
		}
	}
	 
	for (int i = 0; i < 16; i++) {
		if (i != 16)
			printf("%.9f ", dp[i][3]);
		else
			printf("%.9f", dp[i][3]);
	}
	return 0;
}




