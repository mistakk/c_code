#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main() {
	int m, n;
	cin >> n >> m;//注意while处理多个case
	vector<int> goods;
	float stand = 0;
	float cheap = 0;
	float temp;
	int flag;
	float ret = 0, price = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp >> flag;
		if (flag == 1)
			cheap += temp;
		else
			stand += temp;
	}
	price = cheap + stand;
	ret = cheap * 0.8 + stand;
	for (int i = 0; i < m; i++) {
		cin >> temp >> flag;
		if (price >= temp && ret > price - flag)
			ret = price - flag;
	}
	printf("%.2f", ret);

	return 0;

}