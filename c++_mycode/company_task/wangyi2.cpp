using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

bool check(string s) {
	if (s.size() < 8)
		return false;
	vector<char> bad = { '!', '@', '#', '$', '%', '^', '&','*',')','(','_','-','=','+','[',']',',','.','<','>','/','?' };
	vector<string> badstr{ "password", "admin", "qwerty", "hello", "iloveyou", "112233" };
	vector<bool> listcheck(4, false);//da xiao shuzi bad
	for (auto i : s) {
		if (i >= '0' && i <= '9')
			listcheck[2] = true;
		else if (i >= 'a' && i <= 'z')
			listcheck[1] = true;
		else if (i >= 'A' && i <= 'Z')
			listcheck[0] = true;
		else if (find(bad.begin(), bad.end(), i) != bad.end())
			listcheck[4] = true;
	}
	for (int i = 0; i < 4; i++) {
		if (!listcheck[i])
			return false;
	}
	for (int i = 2; i < s.size(); i++) {
		if (s[i - 2] >= 'a' &&s[i - 2] <= 'z')
			if (s[i - 1] >= 'a' &&s[i - 1] <= 'z')
				if (s[i] >= 'a' &&s[i] <= 'z') {
					if (s[i - 2] >= 'a' &&s[i - 2] <= 'z' && (s[i - 1] == s[i - 2] + 1) && (s[i] == s[i - 1] + 1))
						return false;
					if (s[i - 2] >= 'a' &&s[i - 2] <= 'z' && (s[i - 1] == s[i - 2] - 1) && (s[i] == s[i - 1] - 1))
						return false;
				}
		if (s[i - 2] >= 'Z' &&s[i - 2] <= 'Z')
			if (s[i - 1] >= 'Z' &&s[i - 1] <= 'Z')
				if (s[i] >= 'Z' &&s[i] <= 'Z') {
					if (s[i - 2] >= 'A' &&s[i - 2] <= 'Z' && (s[i - 1] == s[i - 2] + 1) && (s[i] == s[i - 1] + 1))
						return false;
					if (s[i - 2] >= 'A' &&s[i - 2] <= 'Z' && (s[i - 1] == s[i - 2] - 1) && (s[i] == s[i - 1] - 1))
						return false;
				}
		if (s[i - 2] >= '0' &&s[i - 2] <= '9')
			if (s[i - 1] >= '0' &&s[i - 1] <= '9')
				if (s[i] >= '0' &&s[i] <= '9')
					for (int j = 0; j <= 3; j++) {
						if (s[i - 2] >= '0' &&s[i - 2] <= '9' && (s[i - 1] == s[i - 2] + j) && (s[i] == s[i - 1] + j))
							return false;
						if (s[i - 2] >= '0' &&s[i - 2] <= '9' && (s[i - 1] == s[i - 2] - j) && (s[i] == s[i - 1] - j))
							return false;
					}
	}
		if (find(badstr.begin(), badstr.end(), s)!= badstr.end())
			return true;
		return true;
}
int main()
{
	string s;
	getline(cin, s);
	int n = atoi(s.c_str());
	vector<bool>res(n, false);
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		res[i] = check(s);
	}
	for (int i = 0; i < n; i++) {
		if (res[i])
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}