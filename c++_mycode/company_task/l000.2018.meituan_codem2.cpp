#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;
int main() {
	int m, n, k;
	cin >> n >> m >> k;
	int a, b;
	long long int maxval = -2147483648, temp;
	int maxidx = 0;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		temp = m * a + (n - m) * b;
		if (temp >= maxval) {
			maxval = m * a + (n - m) * b;
			maxidx = i;
		}
	}
	for (int i = 0; i < k; i++) {
		if (i == maxidx)
			printf("%d", n);
		else
			printf("0");
		if (i != k - 1)
			printf(" ");
	}
	if (0 == k - 1)
		printf(" ");
	return 0;
}