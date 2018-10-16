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
void sortColors(vector<int> &nums)
{
    int i = 0, j = 0, k = nums.size() - 1;
    while (j <= k)
    {
        if (nums[j] == 1)
            ++j;
        else if (nums[j] == 2)
            swap(nums[j], nums[k--]);
        else
            swap(nums[j++], nums[i++]);
    }
    //j faster than i, and when j meet 2, it moves to end, so i will not meet 2
    //so when j meet 0, i must be 0 or 1, if i==1 ok, if i==0, then j must be equal with i
}
void sortColors2(vector<int> &nums)
{
    int i = 0, j = 0, k = nums.size() - 1;
    while (nums[i] == 0)
    {
        ++i, ++j;
    }
    while (nums[k] == 2)
    {
        --k;
    }
    //i is the first not 0, k is the last not 2
    while (j <= k)
    {
        if (nums[j] == 1)
            ++j;
        else if (nums[j] == 2)
        {
            swap(nums[j], nums[k--]);
            while (nums[i] == 0)
            {
                ++i, ++j;
            }
        }
        else
        {
            swap(nums[j], nums[i++]);

            while (nums[k] == 2)
            {
                --k;
            }
        }
    }
}
int main()
{
    vector<int> num{2, 1, 0};
    sortColors(num);
    for (int i = 0; i < num.size(); ++i)
        cout << num[i] << endl;
    return 0;
}