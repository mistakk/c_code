using namespace std;
#include <iostream>
#include <string>
#include <vector>

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
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	bool flag = true;
	if (s1[0] == '-') {
		flag *= -1;
		s1.erase(s1.begin());
	}
	if (s2[0] == '-') {
		flag *= -1;
		s2.erase(s2.begin());
	}
	vector<int> result(s1.size() + s2.size(), 0);
	for (int i = 0; i < s1.size(); ++i)
		for (int j = 0; j < s2.size(); ++j) {
			result[i + j] += (s1[i] - '0') * (s2[j] - '0');
		}
	for (int i = result.size() - 1; i > 0; --i) {
		result[i - 1] += result[i] / 10;
		result[i] %= 10;
	}
	if (flag == false) {
		cout << "-";
	}
	for (int i = 0; i < result.size() - 1; ++i) {
		cout << result[i];
		if ((i == result.size() - 1) && (result[i] != 0))
			cout << result[i];
	}
	cout << endl;
	return 0;
}