using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


void show(vector<int> hehe) {
	for (int i = 0; i != hehe.size(); i++)cout << hehe[i] << " ";
	cout << endl;
}
class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		int pos_1 = -1001;
		int pos_2 = -1001;
		int pos_3 = -1001;
		int neg_1 = 1001;
		int neg_2 = 1001;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] < neg_1) {
				neg_2 = neg_1;
				neg_1 = nums[i];
			}else if (nums[i] < neg_2) {
				neg_2 = nums[i];
			} 
			if (nums[i] > pos_1) {
				pos_3 = pos_2;
				pos_2 = pos_1;
				pos_1 = nums[i];
			}else if (nums[i] > pos_2) {
				pos_3 = pos_2;
				pos_2 = nums[i];
			}else if (nums[i] > pos_3) {
				pos_3 = nums[i];
			}
		}
		if (pos_2*pos_3 > neg_1*neg_2)
			return pos_1*pos_2*pos_3;
		else 
			return pos_1*neg_1*neg_2;
	}
};
void main()
{
	vector<int> nums{ -1,-2,-3};
	Solution a;
	int sum = a.maximumProduct(nums);
	printf("%d\n", sum);
}