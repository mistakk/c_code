#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <set>
using namespace std;
void split(const string &s, vector<int> &sv, const char flag = ' ')
{
    sv.clear();
    istringstream iss(s);
    string temp;

    while (getline(iss, temp, flag))
    {
        sv.push_back(stoi(temp));
    }
    return;
}
void wiggleSort(vector<int> &nums)
{
    int n = nums.size();
    auto mid = nums.begin() + n / 2;
    nth_element(nums.begin(), mid, nums.end());
    int midval = *mid;
    #define A(i) nums[(1 + 2 * (i)) % (n | 1)]
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
    {
        if (A(j) > midval)
            swap(A(i++), A(j++));
        else if (A(j) < midval)
            swap(A(j), A(k--));
        else
            j++;
    }
}
void wiggleSort2(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    vector<int> copy = nums;
    int count = nums.size() / 2;
    for (int i = 0; i < nums.size(); ++++i, ++count)
    {
        nums[i] = copy[count];
    }
    count = 0;
    for (int i = 1; i < nums.size(); ++++i, ++count)
    {
        nums[i] = copy[count];
    }
}

int main()
{
    vector<int> num{1, 2, 3, 4, 5, 6};
    wiggleSort(num);
    for(int i = 0;i<num.size();++i)
    cout<<num[i]<<endl;
    return 0;
}