using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string,int> mp;
		vector<int> re;		
		if (words.size() == 0)
			return re;
		for (auto w : words)
			mp[w]++;
		string temp;
		
		int lens = s.size(), k = words.size(), m=words[0].size();
		for (int  begin = 0; begin <= lens - k*m; begin++) {
			int i = 0;
			unordered_map<string, int>used;
			for (i = 0; i < k; i++) {
				
				temp = s.substr(begin + m*i, m);
				if (mp[temp]>0)
				{
					used[temp]++;
					if (used[temp] > mp[temp])
						break;
				}
				else
					break;
			}
			if (i == k)
				re.push_back(begin);
		}
		return re;
	}
};

void main()
{
	Solution a;
	string s = "wordgoodgoodgoodbestword";
	vector<string> words{ "word", "good", "best", "good" }; 
	vector<int> re;
	re=a.findSubstring(s, words); 
}

