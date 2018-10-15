using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
//10:37

void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
		cout << endl;
		queue<int> s;
}


class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		map<string, int> dic;
		vector<vector<int>> ans;
		for (int i = 0; i < words.size(); ++i)
		{
			string key = words[i];
			reverse(key.begin(), key.end());
			dic[key] = i;
		}

		//handle if "" in words
		if (dic.find("") != dic.end())
		{
			for (int i = 0; i < words.size(); ++i)
			{
				if (words[i] == "")
					continue;
				if (ispalindrome(words[i]))
					ans.push_back({ dic[""], i});
			}
		}

		//handle other
		for (int i = 0; i < words.size(); ++i) {
			for (int j = 0; j < words[i].size(); ++j) {
				string left = words[i].substr(0, j);
				string right = words[i].substr(j, words[i].size() - j);
				// right is palindrom and left can search a pair
				if (dic.find(left) != dic.end() && ispalindrome(right) && dic[left] != i)
					ans.push_back({ i, dic[left] });
				// left is palindrom and right can search a pair
				if (dic.find(right) != dic.end() && ispalindrome(left) && dic[right] != i)
					ans.push_back({ dic[right], i });
			}
		}
		return ans;
	}
	bool ispalindrome(string s)
	{
		int i = 0, j = s.size() - 1;
		while (i<j)
			if(s[i++] != s[j--])
				return false;
		return true;
	}
};
void main()
{
	map<string, int> mp;
	queue<int> q;
	Solution a;
	vector<string> words{ "bb","bababab","baab","abaabaa","aaba","","bbaa","aba","baa","b" };
	vector<vector<int>> t = a.palindromePairs(words);
	for (int i = 0; i < t.size(); ++i) {
		show(t[i]);
	}
	cout << t.size() << endl;
}