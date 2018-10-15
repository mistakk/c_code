using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
float money(float m) {
	float ret = 0;
	if (m <= 5000)
		return ret;
	m = m - 5000;
	if (m <= 3000)
		return m * 0.03;
	m = m - 3000;
	ret += 3000 * 0.03;

	if (m <= 9000)
		return ret + m * 0.1;
	m = m - 9000;
	ret += 9000 * 0.1;

	if (m <= 13000)
		return ret + m * 0.2;
	m = m - 13000;
	ret += 13000 * 0.2;

	if (m <= 10000)
		return ret + m * 0.25;
	m = m - 10000;
	ret += 10000 * 0.25;

	if (m <= 20000)
		return ret + m * 0.3;
	m = m - 20000;
	ret += 20000 * 0.3;

	if (m <= 25000)
		return ret + m * 0.35;
	m = m - 25000;
	ret += 25000 * 0.35;
	return ret + m * 0.45;
}
int main()
{
	int n;
	cin >> n;
	vector<float>rec(n, 0);
	for (int i = 0; i < n; i++) 
		cin >> rec[i];
		
	for (int i = 0; i < n; i++) {
		float aa = money(rec[i]);
		int b = aa;
		if (aa - b >= 0.5)
			b = b + 1;
		cout << b << endl;
	}
}