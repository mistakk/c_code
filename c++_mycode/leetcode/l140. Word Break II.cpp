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
	bool wordBreak2(string s, vector<string>& wordDict) {
		unordered_set<string>set;
		for (int i = 0; i < wordDict.size(); i++)
			set.insert(wordDict[i]);
		int len = s.size();
		vector<bool> flag(len + 1, false);
		flag[0] = true;
		for (int i = 0; i <= len; i++) {
			//查找s的前i个字母是否可凑
			for (int j = 0; j < i; j++) {
				if (flag[j] && set.find(s.substr(j, i - j)) != set.end()) {
					flag[i] = true;
					break;
				}
			}
		}
		return flag[len];
	}
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string>set;
		for (int i = 0; i < wordDict.size(); i++)
			set.insert(wordDict[i]);
		int len = s.size();
		vector<vector<string>> flag(len + 1, vector<string>());
		flag[0].push_back("");
		for (int i = 0; i <= len; i++) {
			//查找s的前i个字母是否可凑
			for (int j = 0; j < i; j++) {
				if (j == 0) {
					if (set.find(s.substr(j, i - j)) != set.end()) {
						flag[i].push_back(s.substr(j, i - j));
					}
				}
				else
					if (flag[j].size() > 0 && set.find(s.substr(j, i - j)) != set.end()) {
						for (int k = 0; k < flag[j].size(); k++)
							flag[i].push_back(flag[j][k] + " " + s.substr(j, i - j));
					}
			}
		}
		return flag[len];
	}
};


int main() {


	return 0;
}