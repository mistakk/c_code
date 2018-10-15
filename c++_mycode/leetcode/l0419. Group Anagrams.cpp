using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <hash_map>
class Solution 
{
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		hash_map<string, vector<string>> mp;
		vector<int>prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
		for (int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			mp[temp].push_back(strs[i]);
		}
	}
};

void main()
{
	Solution a;


}

