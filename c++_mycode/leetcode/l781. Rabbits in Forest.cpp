using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>



class Solution {
public:
	int numRabbits(vector<int>& answers) {
		map<int, int>mp;
		int res = 0;
		for (int i = 0; i < answers.size(); i++)
			mp[answers[i]] += 1;
		auto start = mp.begin();
		auto end = mp.end();
		while (start != end) {
			int num = (*start).first;
			int cnt = (*start).second;
			res += (cnt / (num + 1)) * (num + 1);
			if((cnt % (num + 1)) != 0)
				res += num + 1;
			start++;
		}
		return res;
	}
};

int main() {
	Solution a;
	vector<int> num{ 1,1,0,0,0 };
	cout << a.numRabbits(num) << endl;
	return 0;
}