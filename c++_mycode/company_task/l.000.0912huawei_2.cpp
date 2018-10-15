using namespace std;
#include <iostream>
#include <string>

void my_reverse(string &s, int start, int end) {
	char temp;
	while (start < end) {
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		++start;
		--end;
	}
}
int main() {
	string s;
	getline(cin, s);
	int idx = 0;
	int last = 0;
	while (last < s.size()) {
		while (last != s.size() && s[last] != ' ') {
			++last;
		}
		//last == ' '    or  last ==size
		my_reverse(s, idx, last-1);
		idx = last + 1;
		last = idx;
	}
	cout << s << endl;
	return 0;
}