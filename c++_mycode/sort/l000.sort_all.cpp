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
		//����val���ҵ�����idx��û���ҵ�����-1    (val Ĭ����Ψһ��)
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
		//���ҵ�һ��val���ҵ�����idx��û���ҵ�����-1    (val Ĭ���Ƕ����)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] >= val)  //���ںŸ�right
				right = mid - 1;
			else
				left = mid + 1;
		}
		if (left < num.size() && num[left] == val)
			return left;
		return -1;
	}
	int sort_2(vector<int>num, int val) {
		//�������һ��val���ҵ�����idx��û���ҵ�����-1    (val Ĭ���Ƕ����)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] <= val)   //���ںŸ�left
				left = mid + 1;
			else
				right = mid - 1;
		}
		if (right < num.size() && num[right] == val)
			return right;
		return -1;
	}
	int sort_3(vector<int>num, int val) {
		//�������һ�����ڻ���С��val��Ԫ��idx   (����ж��val�������һ�������û��val��������С��val��Ԫ��)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] <= val)  //���ںŸ�left  ��Ϊ������Է���val ���
				left = mid + 1;
			else
				right = mid - 1;
		}
		return right;
	}
	int sort_4(vector<int>num, int val) {
		//�������һ��С��val��Ԫ��idx   (��������С��val��Ԫ��)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] >= val)  //���ںŸ�right  ��Ϊ���ﲻ�ܷ���val
				right = mid - 1;
			else
				left = mid + 1;
		}
		return right;
	}
	int sort_5(vector<int>num, int val) {
		//���ҵ�һ�����ڻ���С��val��Ԫ��idx   (����ж��val���ص�һ�������û��val������С�Ĵ���val��Ԫ��)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] >= val)  //���ںŸ�right  ��Ϊ������Է���val ���
				right = mid - 1;
			else
				left = mid + 1;
		}
		return left;
	}
	int sort_6(vector<int>num, int val) {
		//���ҵ�һ��С��val��Ԫ��idx   (������С�Ĵ���val��Ԫ��)
		int left = 0, right = num.size() - 1, mid;
		while (left <= right) {
			mid = (left + right) / 2;
			if (num[mid] <= val)  //���ںŸ�left  ��Ϊ���ﲻ�ܷ���val ͬ��
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
		1. ����Ϊ����ģ�棬����left��right������ǰ̨�����Ĳ���
		2. while����һ��Ҫ��<=  �������Ա�֤   rightָ����left��ߡ�
		3. if(num[mid] < val)   //val̫���ˣ�˵��start̫С��
			   start = mid+1;
		   else					//val̫С�ˣ�˵��end̫С��
		       end = mid -1;
		4. ������Ҫ��   (���һ������Ӧ����left)  ��  (�����һ������Ӧ����right)
		5. ������Ҫ��   (������Է���val����ôif������ں��뷵�����)��(������ܷ���val����ôif������ں��뷵��ͬ��)
		*/

	}
};

int main() {
	Solution a;
	return 0;
}
