using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

template<typename T>
void show(vector<T> vec) {
	for (int i = 0; i != vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}
void show(map<string, int> mp) {
	std::map<string, int>::iterator m = mp.begin();
	for (; m != mp.end(); ++m)
		cout << "key is " << m->first << "  value is " << m->second << endl;
}
void show(vector<pair<string, int>> pairvec) {
	std::vector<pair<string, int>>::iterator p = pairvec.begin();
	for (; p != pairvec.end(); ++p)
		cout << "key is " << p->first << "  value is " << p->second << endl;
}


class Solution {
public:
	string fractionToDecimal(int numerator1, int denominator1) {
		if (!numerator1) return "0";

		string ret = "";
		if ((numerator1 < 0) ^ (denominator1 < 0))
			ret += "-";
		if (numerator1 < 0)
			numerator1 *= -1;
		if (denominator1 < 0)
			denominator1 *= -1;

		long numerator = numerator1 < 0 ? (long)numerator1 * (-1) : (long)numerator1;
		long denominator = denominator1 < 0 ? (long)denominator1 * (-1) : (long)denominator1;

		cout << numerator << endl;
		cout << denominator << endl;
			
		std::map<int, int> mp; //yushu
		string loop = "";
		int cnt = 1;
		if (numerator == 0)
			return "0";
		ret += std::to_string(numerator / denominator);

		numerator %= denominator;
		if (numerator != 0)
			ret += ".";
		mp[numerator] = cnt;
		while (numerator != 0)
		{
			numerator *= 10;
			mp[numerator] = cnt+1;
			cnt += 1;
			while (numerator<denominator)
			{
				numerator *= 10;
				cnt += 1;
				loop += "0";
				mp[numerator] = cnt;
			}
			int shang = numerator / denominator;
			int yushu = numerator % denominator;
			loop += std::to_string(shang);

			if (mp[yushu] != 0 )
			{
				int a = 0;
				loop += ")";
				for (int j = 0; j < mp[yushu] -1; ++j)
					ret += loop[j];
				ret += "(";
				for (int j = mp[yushu] -1; j<loop.size(); ++j)
					ret += loop[j];
				return ret;
			}

			numerator = yushu;
			mp[numerator] = cnt;
		}
		ret += loop;
		return ret;
	}
};

void main()
{
	map<string, int> mp;
	queue<int> q;
	Solution a;
	cout << "sys start!" << endl;
	int aa = -2147483648;
	string ret = a.fractionToDecimal(-1, aa);
	cout << ret << endl;
}
