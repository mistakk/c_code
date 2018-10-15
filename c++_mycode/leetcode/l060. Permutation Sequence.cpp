using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
	string getPermutation(int n, int k) {
		string re;
		vector<int> num,a,test;
		k--;
		int temp = 1;
		for (int i = 1; i <= n; i++) {
			re += '0' + i;

			temp *= i;
			num.insert(num.begin(), temp);
		
			test.insert(test.begin(), k%(i+1));
			k = k/ (i + 1);

		}
		/*cout << "test" << endl;
		for (int i = 0; i < test.size(); i++)
			cout << test[i] << " " << endl;
		*/
		/*
		for (int i = 0; i < n; i++) {
			temp = k / num[i];
			k = k%num[i];
			a.push_back(temp); 
		}*///a is the same as test
		/*for (int i = 0; i < a.size(); i++)
			cout << a[i] << " " << endl;
		*/
		if (test[0] == 1) {
			reverse(re.begin(), re.end());
			return re;
		}
		for (int i = 1; i < n; i++) {
			if (test[i] != 0) {
				swap(re[i-1],re[i+ test[i]-1]);
				sort(re.begin() + i , re.end());
			}
		}
		return re;
	}
};
void main()
{
	Solution a;
	string re=a.getPermutation(3,6);
	cout << re << endl;
}

