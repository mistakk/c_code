using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0)
			return false;
		while (n>1) {
			if (n % 3)
				return false;
			n /= 3;
		}
		return true;
	}
};

void main()
{
	Solution x;
	int a = 7;
	cout << x.isPowerOfTwo(a) << endl;

}