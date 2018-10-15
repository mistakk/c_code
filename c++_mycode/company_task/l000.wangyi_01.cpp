using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int maxval = -10;
	maxval = max(maxval, a + b + c);
	maxval = max(maxval, a + b * c);
	maxval = max(maxval, a * b + c);
	maxval = max(maxval, a * b * c);
	maxval = max(maxval, (a + b) * c);
	maxval = max(maxval, a*(b + c));
	cout<<maxval;
	return 0;
}