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
	string mostCommonWord(string paragraph, vector<string>& banned) {
		map<string, int> mp;
		string temp = "";
		int max = -1;
		string ret;
		paragraph += " ";
		for (int i = 0; i < paragraph.size(); i++) {
			if (check(paragraph[i]))
				if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
					temp += paragraph[i] - 'A' + 'a';
				else
					temp += paragraph[i];
			else if (temp.size() != 0) {
				mp[temp] += 1;
				if (find(banned.begin(), banned.end(), temp) == banned.end()) {
					if (mp[temp] > max) {
						ret = temp;
						max = mp[temp];
					}
				}
				temp = "";
			}
		}
		return ret;
	}

	bool check(char s) {
		return (s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z');
	}
};

int main() {
	Solution a;
	string ss = "Bob";
	vector<string> banned{ "" };
	cout << a.mostCommonWord(ss, banned) << endl;
}