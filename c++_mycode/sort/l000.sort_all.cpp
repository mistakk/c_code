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




class Solution {
public:
	int sort_0(vector<int>& num, int val) {
		//查找val，找到返回idx，没有找到返回-1    (val 默认是唯一的)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] == val)
				return mid;
			else if (num[mid] < val)
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
	}
	int sort_1(vector<int>num, int val) {
		//查找第一个val，找到返回idx，没有找到返回-1    (val 默认是多个的)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] >= val)  //等于号给right
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (left < num.size() && num[left] == val)
			return left;
		return -1;
	}
	int sort_2(vector<int>num, int val) {
		//查找最后一个val，找到返回idx，没有找到返回-1    (val 默认是多个的)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] <= val)   //等于号给left
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (right < num.size() && num[right] == val)
			return right;
		return -1;
	}
	int sort_3(vector<int>num, int val) {
		//查找最后一个等于或者小于val的元素idx   (如果有多个val返回最后一个，如果没有val返回最大的小于val的元素)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] <= val)  //等于号给left  因为这里可以返回val 异号
				left = mid + 1;
			else
				right = mid - 1;
		}
		return right;
	}
	int sort_4(vector<int>num, int val) {
		//查找最后一个小于val的元素idx   (返回最大的小于val的元素)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] >= val)  //等于号给right  因为这里不能返回val
				right = mid - 1;
			else
				left = mid + 1;
		}
		return right;
	}
	int sort_5(vector<int>num, int val) {
		//查找第一个等于或者小于val的元素idx   (如果有多个val返回第一个，如果没有val返回最小的大于val的元素)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] >= val)  //等于号给right  因为这里可以返回val 异号
				right = mid - 1;
			else
				left = mid + 1;
		}
		return left;
	}
	int sort_6(vector<int>num, int val) {
		//查找第一个小于val的元素idx   (返回最小的大于val的元素)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] <= val)  //等于号给left  因为这里不能返回val 同号
				left = mid + 1; 
			else
				right = mid - 1;
		}
		return left;
	}
	int sort_summary(vector<int>num, int val) {
		/*
		int left = 0, right = num.size(), mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] ?? val) {
				???
			}
			else 
				???

		}
		return ??
		*/
		/*
		1. 以上为函数模版，其中left和right可以是前台传来的参数
		2. while后面一定要是<=  这样可以保证   right指针在left左边。
		3. if(num[mid] < val)   //val太大了，说明start太小了
			   start = mid+1;
		   else					//val太小了，说明end太小了
		       end = mid -1;
		4. 根据需要是   (求第一个：对应返回left)  或  (求最后一个：对应返回right)
		5. 根据需要是   (如果可以返回val，那么if那里等于号与返回异号)；(如果不能返回val，那么if那里等于号与返回同号)
		*/

	}
};

int main() {
	Solution a;
	return 0;
}
