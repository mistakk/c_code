using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}


class Solution {
public:
	int singleNonDuplicate(vector<int>& nums) {
		int n = nums.size();
		int min = 0, max = n-1, mid;
		while (min < max) {
			mid = (min + max) / 2;
			if (mid % 2 == 1)
				mid -= 1;
			if (nums[mid] != nums[mid + 1])
				max = mid;
			else
				min = mid + 2;
		}
		return nums[min];
	}

	int bsearch(vector<int>& nums, int key) {
		int mi = 0, ma = nums.size()-1, mid = 0;
		while (mi <= ma) {
			mid = (mi + ma) / 2;
			if (nums[mid] < key)
				ma = mid - 1;
			else if (nums[mid] > key)
				mi = mid + 1;
			else
				return mi;
		}
		return -1;
	}
};
void main()
{

	map<string, int> mp;
	queue<int> q;
	string s = "123456789123456789";
	printf("s\n", s);
	cout << "checkbad letter" << endl;

}