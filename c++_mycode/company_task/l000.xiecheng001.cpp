using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <stdio.h>
int main()
{
	long num;
	int cnt = 0;
	cin>>num;
	for (int i = 0; i < 64; i++)
	{
		if ((1ll << i) & num)
			cnt += 1;
	}
	cout << cnt << endl;
}
int findf(vector<int> &father, int x) {
	if (father[x] != x)
		father[x] = findf(father, father[x]);
	return father[x];
}
void unionp(vector<int> &father, int a, int b) {
	int pa = findf(father, a);
	int pb = findf(father, b);
	if (pa != pb) {
		father[pb] = pa;
	}
}

