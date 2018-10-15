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

class Solution {
public:
	int numJewelsInStones2(string J, string S) {
		map<char, int> mp;
		int cnt = 0;
		for (int i = 0; i < S.size(); i++) 
			mp[S[i]] += 1;
		for (int i = 0; i < J.size(); i++) 
			cnt += mp[J[i]];
		return cnt;
	}
	int numJewelsInStones(string J, string S) {
		vector<bool> flag('z' - 'A', false);
		int cnt = 0;
		for (int i = 0; i < J.size(); i++)
			flag[J[i] - 'A'] = true;
		int jddd = 0;
		for (int i = 0; i < S.size(); i++) 
			if(flag[S[i] - 'A'])
				cnt++;
		
		return cnt;
	}
};

int main() {
	string S = "kxg";
	string J = "ngm";
	Solution a;
	cout << a.numJewelsInStones(J, S) << endl;
	return 0;
}