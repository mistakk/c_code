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

//链接：https ://www.nowcoder.com/acm/contest/5/A
//给定两个整数 l 和 r ，对于所有满足1 ≤ l ≤ x ≤ r ≤ 10 ^ 9 的 x ，把 x 的所有约数全部写下来。对于每个写下来的数，只保留最高位的那个数码。求1～9每个数码出现的次数。

//计算1到end范围内每个数为约数，总共可以有多少个倍数可取  
long long getDivisor(long long val, long long end) {
	if (end == 0 || val == 0)    return 0;
	//将end固定为两者的最小值  
	end = min(val, end);
	long long t = 0, res = 0;
	for (t = 1; t <= end && t*t <= val; t++)     
		res += val / t;
	for (long long i = val / t; i >= val / end; i--)   
		res += (min(end, val / i) - val / (i + 1))*i;
	return res;
}

//对于取值范围，计算取值范围两端到1有多少个数  
long long getVal(long long val, long long left, long long right) {
	return getDivisor(val, right) - getDivisor(val, left - 1);
}

//计算对于区间左右取值，对于在取值范围每个取值（约数）有多少个数  
long long calcu(long long l, long long r, long long left, long long right) {
	return getVal(r, left, right) - getVal(l - 1, left, right);
}

int main() {
	int l = 0, r = 0;
	//cin >> l >> r;
	l = 1, r = INT32_MAX / 100;
	vector<long long> res(10, 0);
	//根据本题取约数的范围，大概可以固定范围在10的10次方内  
	long long tmp = 1;
	for (int i = 0; i < 10; i++) {
		//每一次迭代求一下每个j开头的约数的数量  
		for (int j = 1; j <= 9; j++) {
			//固定每一次的约数取值范围  
			long long left = j * tmp, right = (j + 1)*tmp - 1;
			res[j] += calcu(l, r, left, right);
		}
		tmp *= 10;
	}
	for (int i = 1; i <= 9; i++) {
		cout << res[i] << endl;
	}
	return 0;
}
