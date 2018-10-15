using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int merge(vector<long long>&sums, int left, int right, const int &lower, const int &upper) {
        if (right - left <= 1) return 0;
        int mid = (left + right) / 2;
        int count = merge(sums, left, mid, lower, upper) + merge(sums, mid, right, lower, upper);
        int i = mid, j = mid;
        for (int idx = left; idx < mid; ++idx) {
            while (i < right && sums[i] - sums[idx] < lower)
                i += 1;
            while (j < right && sums[j] - sums[idx] <= upper)
                j += 1;
            count += j - i;
        }
        sort(sums.begin() + left, sums.begin() + right);
        return count;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        return merge(sums, 0, n + 1, lower, upper);
    }
};

void main()
{
    Solution a;
    vector<int>num{ -2,5,-1 };
    cout << a.countRangeSum(num, -2, 2);
}

