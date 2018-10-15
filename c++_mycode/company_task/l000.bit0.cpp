using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

void revertWord(char *p, char *p1)
{
	char c;
	for (; p < p1; p++, p1--) {
		c = *p;
		*p = *p1;
		*p1 = c;
	}
}

void revert(char *p)
{
	char *p1;
	while (*p && *p == ' ')
		p++;
	if (!*p)
		return;
	p1 = p;
	while (*p && *p != ' ')
		p++;
	revertWord(p1, p - 1);
	revert(p);
}

int main2()
{
	char line[] = "To be or not to be";
	revert(line);
	printf("%s.\n", line);
	return 0;
}
int main()
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= i; j++) {
			cout << j << "*" << i << "=" << i * j << "  ";
			if (i <= 4 && j == 2)
				cout << " ";
		}
		cout << endl;
	}
}