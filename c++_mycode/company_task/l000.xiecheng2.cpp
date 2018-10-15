using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
#include <stdio.h>
class obj {
public:
	int idx;
	int start;
	int end;
	obj(int a, int b, int c);
};
obj::obj(int a, int b, int c){
	idx = a;
	start = b;
	end = c;
};
int main()
{
	int n;
	int flag;
	cin >> n >> flag;
	int idx, start, end;
	set<int>vec;
	for (int i = 0; i < n; i++) {
		cin >> idx >> start >> end;
		if (start <= flag && end >= flag) {
			vec.insert(idx);
		}
	}
	if (vec.size() == 0)
		cout << "null" << endl;
	else {
		set<int>::iterator it = vec.begin();
		for (; it!=vec.end();++it)
			cout << *it << endl;
	}
	return 0;
}

