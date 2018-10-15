using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	string frequencySort(string s) {
		std::map<char, int> m;
		std::string::iterator i = s.begin();
		for(char c:s)
			m[c] += 1;
		std::string ret; 
		int n = s.size();
		std::vector<string> vec(n+1, "");
		for(std::map<char, int>::iterator i = m.begin(); i != m.end(); ++i)
			vec[i->second].append(i->second,i->first);
		for (int i = n; i > 0; --i)
			if (!vec[i].empty())
				ret += vec[i];
		return ret;
	}
};
void main()
{
	map<string, int> mp;
	queue<int> q;
	Solution a;
	string aa = a.frequencySort("eeeee");
	cout << aa << endl;

}









