using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <map>


int main() {
	map<char, int>mp;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i)
		mp[s[i]] += 1;
	for(int j =s.size()-1;j>=0;--j)
		if (mp[s[j]] == 1) {
			printf("%c", s[j]);
			return 0;
		}
	printf("NULL\n");
	return 0;
}
