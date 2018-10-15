using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> re;
		vector<int> a(n, 1);
		for (int i = 0; i < n; i++)
			re.push_back(a);
		int count = 1;
		for (int i = 0; i < n / 2; i++) {
			/*for (int j = 0; j< n - 1 - 2 * i; j++) {
				re[i][i + j] = count++;
			}
			for (int j = 0; j< n - 1 - 2 * i; j++) {
				re[i + j][n - 1 - i] = count++;
			}
			for (int j = 0; j< n - 1 - 2 * i; j++) {
				re[n - 1 - i][n - 1 - i - j] = count++;
			}
			for (int j = 0; j< n - 1 - 2 * i; j++) {
				re[n - 1 - i - j][i] = count++;
			}
			*/	
			for (int j = 0; j< n - 1 - 2 * i; j++) {
				re[i][i + j] = count;
				re[i + j][n - 1 - i] = n - 1 - 2 * i + +count;
				re[n - 1 - i][n - 1 - i - j] = (n - 1 - 2 * i)*2+count;
				re[n - 1 - i - j][i] = (n - 1 - 2 * i)*3+count;
				count++;
			}
			count += (n - 1 - 2 * i) *3;
		}
		if (n % 2)
			re[ n / 2][ n / 2] = n*n;
		return re;
	}
};
void main()
{
	Solution a;
	int n = 5;
	vector<vector<int>> re = a.generateMatrix(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << re[i][j] << " ";
		cout << endl;
	}
}

