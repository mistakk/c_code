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

//0814
class Solution {
public:
	int minSwapsCouples(vector<int>& row) {
		int n = row.size() / 2;
		map<int, int> mp;
		vector<bool>finish(n, false);
		int cnt = 0;
		int idx, key, val, par;
		for (int i = 0; i < n; i++) {
			mp[row[2 * i]] = row[2 * i + 1];
			mp[row[2 * i + 1]] = row[2 * i];
		}
		for (idx = 0; idx < n; idx++) {//idx = 0
			if (finish[idx])
				continue;
			key = idx * 2;//key = 0
			val = mp[key];//val = 6
			par = val + 1 - 2 * (val % 2);//par = 7
			while (idx != par / 2) {
				finish[par/2] = true;
				key = par; //key = 7
				val = mp[key]; //val = 4;
				par = val + 1 - 2 * (val % 2);//val = 5
				cnt++;
			}
		}
		return cnt;
	}
};

int main() {
	Solution a;
	vector<int>row{ 0,2,1,4,3,5 };
	//cout << a.minSwapsCouples(row) << endl;
	vector<int>::iterator it = row.end();
	it = row.erase(it, it+1);
	cout << *it << endl;


	return 0;
}
