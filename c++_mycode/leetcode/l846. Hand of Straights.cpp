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
	bool isNStraightHand(vector<int>& hand, int W) {
		int size = hand.size();
		if (size % W != 0)
			return false;
		map<int, int> mp;
		sort(hand.begin(), hand.end());
		for (int i = 0; i < size; i++) {
			mp[hand[i]]++;
		}
		int minstart = hand[0];
		int cntnew = mp[minstart];
		int cnt_all = size;
		while (cnt_all !=0) {
			bool nextflag = true;
			int start = minstart;
			int cnt = cntnew;
			cnt_all -= cnt*W;
			for (int j = 0; j < W; j++) {
				if (mp[start + j] < cnt)
					return false;
				else {
					mp[start + j] = mp[start + j] - cnt;
					if (mp[start + j] != 0 && nextflag) {
						minstart = start + j;
						nextflag = false;
						cntnew = mp[start + j];
					}
				}
			}

			if (cnt_all !=0 && minstart == start) {
				minstart = minstart + W;
				while ( mp[minstart] == 0 && minstart < INT_MAX) {
					minstart++;
				}
				cntnew = mp[minstart];
			}
		}
		return true;
	}
};

int main() {
	Solution a;
	vector<int> hand = { 34,80,89,15,38,69,19,17,97,98,26,77,8,31,79,70,103,3,13,21,81,53,33,14,60,68,33,59,84,23,97,90,76,82,66,83,23,22,16,18,98,25,16,61,84,100,4,68,101,25,23,9,10,55,2,67,39,52,102,99,40,11,83,24,81,53,96,23,13,24,99,67,22,51,31,58,78,88,5,15,24,32,81,91,96,16,54,22,56,69,14,82,32,34,83,24,37,82,54,21 };
	int w = 4;
	
	cout << a.isNStraightHand(hand,w)<< endl;
	return 0;
}