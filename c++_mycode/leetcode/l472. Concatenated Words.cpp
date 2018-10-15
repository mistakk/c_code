using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		vector<string> res;
		set = unordered_set<string>(words.begin(), words.end());
		for (int i = 0; i < words.size(); i++) {
			if (wordbreak(words[i]) && words[i].size()>0)
				res.push_back(words[i]);
		}
		return res;
	}
	bool wordbreak(string s){
		int len = s.length();
		set.erase(s);
		vector<bool> flag(len + 1, false);
		flag[0] = true;
		for (int i = 0; i <= len; i++) {
			for (int j = 0; j < i; j++) {
				if (flag[j] && set.find(s.substr(j, i - j)) != set.end()) {
					flag[i] = true;
					break;
				}
			}
		}
		set.insert(s);
		return flag[len];
	}
	unordered_set<string> set;
};


int main() {
	unordered_set<string> set;
	cout << set.size() << endl;
	set.insert("ss");
	cout << set.size() << endl;
	set.erase("ss");
	cout << set.size() << endl;

	return 0;
}