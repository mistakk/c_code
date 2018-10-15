using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    int merge2(vector<int>&nums, int left, int right) {
        if (left >= right) return 0;
        int mid = (left + right) / 2;
        int cnt = merge2(nums, left, mid) + merge2(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; ++i) {
            while (j <= right && nums[i] > 2.0*nums[j])
                j++;
            cnt += j - mid - 1;
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return cnt;
    }

    int merge1(vector<int>&nums, int left, int right)
    {
        if (left >= right)
            return 0;
        int mid = (left + right) / 2;
        int cnt = merge1(nums, left, mid) + merge1(nums, mid + 1, right);
        for (int i = left, j = mid + 1; i <= mid; ++i)
        {
            while (j <= right && nums[i] / 2.0 > nums[j])
                ++j;
            cnt += j - (mid + 1);
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return cnt;
    };
    int reversePairs(vector<int>& nums)
    {
        return merge2(nums, 0, nums.size() - 1);
    }
};
void main()
{
    Solution a;
    vector<int>num{ 4,3,2,1 };
    cout << a.reversePairs(num);
}

