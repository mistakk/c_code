using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_set>

#include <fstream>
#include <numeric>

//Given two arrays of length m and n with digits 0 - 9 representing two numbers.Create the maximum number of length k <= m + n from digits of the two.The relative order of the digits from the same array must be preserved.Return an array of the k digits.
//
//Note: You should try to optimize your time and space complexity.
//
//	Example 1 :
//
//	Input :
//	nums1 = [3, 4, 6, 5]
//	nums2 = [9, 1, 2, 5, 8, 3]
//	k = 5
//	Output :
//	[9, 8, 6, 5, 3]
//Example 2 :
//
//	Input :
//	nums1 = [6, 7]
//	nums2 = [6, 0, 4]
//	k = 5
//	Output :
//	[6, 7, 6, 0, 4]
//Example 3 :
//
//	Input :
//	nums1 = [3, 9]
//	nums2 = [8, 9]
//	k = 3
//	Output :
//	[9, 8, 9]
class Solution {
public:
	vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<int> init(k, 0), res, temp1, temp2;
		for (int i = 0; i <= k; i++) {
			if (nums1.size() >= i && nums2.size() >= k - i) {
				if (i != 0)
					temp1 = ff(nums1, i);
				if (k - i != 0)
					temp2 = ff(nums2, k - i);
				if (i != 0 && k - i != 0)
					res = combine(temp1, temp2);
				else if (i == 0)
					res = temp2;
				else
					res = temp1;
			}
			else
				continue;
			if (compare(res, init)) {
				init = res;
			}
		}
		return init;
	}
	vector<int> combine(vector<int>n1, vector<int>n2) {
		int s1 = 0, s2 = 0;
		vector<int> res(n1.size() + n2.size(), 0);
		while (!(s1 == n1.size() || s2 == n2.size())) {
			int idx = 0;
			while (s1 + idx < n1.size() && s2 + idx < n2.size() && n1[s1 + idx] == n2[s2 + idx])
				idx++;
			if (s1 + idx == n1.size()) {
				res[s1 + s2] = n2[s2];
				s2++;
				continue;
			}
			if (s2 + idx == n2.size()) {
				res[s1 + s2] = n1[s1];
				s1++;
				continue;
			}
			if ((n1[s1 + idx] > n2[s2 + idx])) {
				res[s1 + s2] = n1[s1];
				s1++;
			}
			else {
				res[s1 + s2] = n2[s2];
				s2++;
			}
		}
		while (s1 != n1.size()) {
			res[s1 + s2] = n1[s1];
			s1++;
		}
		while (s2 != n2.size()) {
			res[s1 + s2] = n2[s2];
			s2++;
		}
		return res;
	}
	vector<int> ff(vector<int> num, int cnt) {
		vector<int> res(cnt, 0);
		int maxval = num[0];
		int start = 0;
		if (num.size() == cnt)
			return num;
		for (int i = 0; i < cnt; i++) { //choose the i'th num from [start, size - cnt]
			maxval = num[start];
			for (int j = start; j <= num.size() - cnt + i; j++) {
				if (num[j] > maxval) {
					maxval = num[j];
					start = j;
				}
			}
			start++;
			res[i] = maxval;
		}
		return res;
	}
	bool compare(vector<int> a, vector<int> b) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == b[i])
				continue;
			else if (a[i] > b[i])
				return true;
			else
				return false;
		}
		return true;
	}
};
int main() {
	Solution a;
	vector<int> dd{ 5,1,0 };
	vector<int> dd2{ 5,2,1 };
	vector<int> dd3 = a.maxNumber(dd, dd2, 3);
	for (auto d : dd3) {
		cout << d << endl;
	}
	return 0;
}



