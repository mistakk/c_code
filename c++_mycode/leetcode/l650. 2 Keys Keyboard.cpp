using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
	int minSteps(int n) {
		//record[n] is the min steps of n*'A' we need.
		vector<int> record(1001, 0);
		//init the steps
		//record[i] < 0 means we has not processed.
		for (int i = 2; i <= 1000; i++)
			record[i] = -i;
		record[1] = 0;
		//helper(n) find the min steps of n*'A'.
		helper(n, record);
		return record[n];
	};
	void helper(int n, vector<int> &record) {
		//if record[n] has processed, we stop the recursion
		if (record[n] >= 0)
			return;
		//if n = a*b, c*d ......
		// f(n)1 = min(f(a) + b, f(b) + a);    equation 1
		// f(n)2 = min(f(c) + d, f(d) + c);    equation 2
		// f(n) = min{f(n)1, f(n)2, f(n)3, ... }
		// equation 1: the former is get a*'A' first and then copy (b-1) times, and later is get b*'A' first.
		for (int i = 2; i <= sqrt(n); ++i) {
			if (n % i == 0) {
				int m = n / i;
				helper(i, record);
				helper(m, record);
				if (record[n] >= 0) 
					record[n] = min(record[m] + i, record[n]);
				else 
					record[n] = record[m] + i;
				record[n] = min(record[n], record[i] + m);
			}
		}
		//if process over, we set record[n] as > 0
		if (record[n] < 0)
			record[n] = -record[n];
	}
};



int main() {
	Solution a;
	for (int i = 100; i < 101; i++)
		cout << "i = " << i << " , min is " << a.minSteps(i) << endl;

	return 0;
}