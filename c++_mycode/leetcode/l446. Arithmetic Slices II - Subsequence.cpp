using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
class Solution {
public:
	int numberOfArithmeticSlices2(vector<int>& A) {
		//init();
		int n = A.size();
		int res = 0;
		if (n < 3)
			return 0;
		map<int, set<int>> mp;
		for (int i = 0; i < n; i++)
			mp[A[i]].insert(i);
		vector<vector<int>> cnt(n, vector<int>(n, 0));

		for (int i = 2; i < n; i++) {
			for (int j = 1; j < i; j++) {
				long diff = 2 * A[j] - A[i];
				for (int k : mp[diff]) {
					if (k >=j)
						continue;
					cnt[j][i] += cnt[k][j] + 1;
				}
				res += cnt[j][i];
			}
		}
		return res;
	}

	int numberOfArithmeticSlices(vector<int>& A) {
		//init();
		int n = A.size();
		int res = 0;
		if (n < 3)
			return 0;
		vector<map<long, int>> mp(n, map<long, int>());
		
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < i; j++) {
				long step = A[i] - A[j];
				mp[i][step] += 1;
				int tmp = mp[j].count(step) ? mp[j][step] : 0;
				if (tmp) {
					res += tmp;
					mp[i][step] += mp[j][step] + 1;
				}
			}
		}
		return res;
	}

};
void main()
{
	Solution a;
	vector<int> x{ 0,1,2,3};
	int xx = a.numberOfArithmeticSlices(x);
	cout << xx << endl;
}



