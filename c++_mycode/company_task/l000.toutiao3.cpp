#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100005;
struct Node {
	int l, r, m;              //m存最大值 
};
vector<Node> node1(maxn * 4);
vector<Node> node2(maxn * 4);
int a[maxn]; 
int b[maxn];
void build1(int t, int l, int r)            //建树函数 
{
	node1[t].l = l;
	node1[t].r = r;
	if (l == r)
	{
		node1[t].m = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build1(t * 2, l, mid);
	build1(t * 2 + 1, mid + 1, r);
	node1[t].m = max(node1[t * 2].m, node1[t * 2 + 1].m);    //保持每个节点m的最大值 
}
void build2(int t, int l, int r)            //建树函数 
{
	node2[t].l = l;
	node2[t].r = r;
	if (l == r)
	{
		node2[t].m = b[l];
		return;
	}
	int mid = (l + r) / 2;
	build2(t * 2, l, mid);
	build2(t * 2 + 1, mid + 1, r);
	node2[t].m = min(node2[t * 2].m, node2[t * 2 + 1].m);    //保持每个节点m的最小值 
}
int find_max(int t, int l, int r)
{
	if ((l == node1[t].l) &&(r == node1[t].r))
		return node1[t].m;
	int s;
	if (r <= node1[t * 2].r) 
		s = find_max(t * 2, l, r);
	else if (l >= node1[t * 2 + 1].l) 
		s = find_max(t * 2 + 1, l, r);
	else 
		s = max(find_max(t * 2, l, node1[t * 2].r), find_max(t * 2 + 1, node1[t * 2 + 1].l, r));
	return s;
}
int find_min(int t, int l, int r)
{

	if (l == node2[t].l&&r == node2[t].r) 
		return node2[t].m;
	int s;
	if (r <= node2[t * 2].r) 
		s = find_min(t * 2, l, r);
	
	else if (l >= node2[t * 2 + 1].l) 
		s = find_min(t * 2 + 1, l, r);
	else 
		s = min(find_min(t * 2, l, node2[t * 2].r), find_min(t * 2 + 1, node2[t * 2 + 1].l, r));
	return s;
}
int main()
{
	int n;
	cin >> n;
	vector<int> num2(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		build1(1, 1, n);
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		build2(1, 1, n);
	}
	int cnt = 0;
	for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++)
			if (find_min(1,l,r) > find_max(1, l, r))
				cnt += 1;
	cout << cnt << endl;
	return 0;
}