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

class Master {
public:
	int guess(string word);
};
class Solution {
public:
	void findSecretWord2(vector<string>& wordlist, Master& master) {
		for (int i = 0, x = 0; i < 10 && x < 6; i++) {
			vector<string> wordlist2;
			string word = wordlist[rand() % wordlist.size()];
			x = master.guess(word);
			for (int k = 0; k < wordlist.size(); k++) {
				if (match(word, wordlist[k]) == x)
					wordlist2.push_back(wordlist[k]);
			}
			wordlist = wordlist2;
		}
	}
	void findSecretWord(vector<string>& wordlist, Master& master) {
		for (int i = 0, x = 0; i < 10 && x < 6; ++i) {
			map<string, int> count;
			for (string w1 : wordlist) 
				for (string w2 : wordlist) 
					if (match(w1, w2) == 0) 
						count[w1]++;
			//minimax is the best difference in all data
			pair<string, int> minimax = make_pair(wordlist[0], 1000);
			for (string w : wordlist) 
				if (count[w] <= minimax.second) 
					minimax = make_pair(w, count[w]);
			x = master.guess(minimax.first);
			vector<string> wordlist2;
			for (string w : wordlist) 
				if (match(minimax.first, w) == x)
					wordlist2.push_back(w);
			wordlist = wordlist2;
		}
	}
	int match(string a, string b) {
		int cnt = 0;
		for (int i = 0; i < 6; i++) {
			if (a[i] == b[i])
				cnt++;
		}
		return cnt;
	}
};


class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {

	}
};

int main() {
	Solution a;
	return 0;
}