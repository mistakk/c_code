using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<string, vector<string>> mp;
		for (int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			mp[temp].push_back(strs[i]);
		}

		vector<vector<string>> re;
		for (map<string, vector<string>>::iterator s = mp.begin(); s != mp.end();s++) {
			re.push_back((*s).second);
		}
		cout << re[0].size();
		return re;
}
	vector<vector<string>> groupAnagrams2(vector<string>& strs) {
		map<string, int> mp;
		vector<vector<string>>re(strs.size()+1);
		if (strs.size()==1)
		{
			re[0].push_back(strs[0]);
			re.pop_back();
			return re;
		}
		int count = 1;
		for (int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if (mp[temp] > 0) {
				re[mp[temp]].push_back(strs[i]);
			}
			else {
				mp[temp] = count;
				count++;
				re[mp[temp]].push_back(strs[i]);
			}
		}
		for (int i = 0; i < strs.size() - count+1 ; i++)
			re.pop_back();
		vector<string> temp = re.back();
		re[0] = temp;
		re.pop_back();
		return re;
	}
};

void main()
{
	Solution a;
	vector<string> strs = { "","" };
	a.groupAnagrams2(strs);

}

