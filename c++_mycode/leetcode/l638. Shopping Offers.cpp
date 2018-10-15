using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    void addthis(vector<int> &a, const vector<int> &b) {
        for (int i = 0; i < a.size(); i++)
            a[i] += b[i];
    }
    void subthis(vector<int> &a, const vector<int> &b) {
        for (int i = 0; i < a.size(); i++)
            a[i] -= b[i];
    }
    int multiply(const vector<int>a, const vector<int>b) {
        int ret = 0;
        for (int i = 0; i < a.size(); i++)
            ret += a[i] * b[i];
        return ret;
    }
    bool xiaoyu0(const vector<int>a) {
        for (int i = 0; i < a.size(); i++)
            if (a[i] < 0)
                return true;
        return false;
    }
    int shoppingOffers2(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        if (xiaoyu0(needs))
            return INT_MAX;
        int m = cost + multiply(price, needs);
        for (int i = 0; i < special.size(); i++) {
            if (cost + special[i].back() > m)
                continue;
            subthis(needs, special[i]);
            m = min(m, shoppingOffers2(price, special, needs, cost + special[i].back()));
            addthis(needs, special[i]);
        }
        return m;
    }


    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();//product cnt
        int cnt = special.size();//special cnt
        int max_size = pow(7, n);
        int idx;
        bool failed;
        int k;
        int newpos;
        int left;

        vector<int>dp(max_size, INT_MAX);
        //without special
        for (int j = 0; j < max_size; j++) { // each postion you sit
            int k = j;
            int money = 0;
            for (int i = 0; i < n; i++) { // i is the nth product
                int left = k % 7;
                k = k / 7;
                money += left * price[i];
            }
            dp[j] = money;
        }

        for (int j = 0; j < max_size; j++) { // nowpos you sit
            for (auto ofr : special) { // each ofr you can chose
                newpos = j; // newpos is now pos add ofr

                failed = false;
                k = j;
                idx = 1;
                for (int i = 0; i < n; i++) { // i is the nth product
                    left = k % 7;
                    k = k / 7;
           /*         if (left + ofr[i] >= 7) {
                        failed = true;
                        break;
                    }*/
                    newpos += idx * ofr[i];
                    idx *= 7;
                }

                if (failed == false && dp[j] + ofr.back() < dp[newpos])
                    dp[newpos] = dp[j] + ofr.back();
            }
        }

        //cout the needs
        idx = 1;
        left = 0;
        for (int i = 0; i < n; i++) { // i is the nth product
            left += idx * needs[i];
            idx *= 7;
        }
        return dp[left];
    }
};

int main()
{
    Solution a;
    vector<int>price{ 1, 1, 10, 3, 4, 1 };
    vector<vector<int>>special{ { 4, 1, 6, 6, 0, 5, 17 },{ 6, 3, 1, 5, 5, 0, 16 },{ 3, 5, 4, 4, 0, 6, 7 },{ 1, 3, 0, 2, 5, 5, 18 },{ 2, 6, 0, 6, 5, 4, 18 },{ 5, 2, 6, 3, 4, 5, 3 },{ 2, 5, 6, 5, 2, 3, 3 },{ 0, 1, 2, 1, 4, 0, 16 },{ 2, 5, 0, 4, 2, 5, 4 },{ 0, 2, 4, 4, 4, 3, 11 },{ 1, 2, 4, 3, 5, 3, 9 },{ 0, 5, 1, 1, 6, 1, 8 },{ 3, 6, 2, 3, 4, 0, 8 },{ 6, 5, 1, 4, 5, 3, 3 },{ 3, 6, 6, 4, 6, 4, 1 },{ 3, 5, 4, 3, 3, 3, 8 },{ 2, 4, 1, 3, 3, 1, 7 },{ 5, 0, 4, 2, 5, 3, 15 },{ 4, 6, 4, 5, 6, 3, 3 },{ 3, 5, 4, 6, 4, 1, 17 },{ 5, 4, 1, 1, 6, 2, 8 },{ 0, 2, 2, 3, 2, 6, 3 },{ 5, 3, 3, 2, 0, 5, 10 },{ 4, 1, 6, 1, 5, 3, 16 },{ 0, 3, 6, 5, 0, 1, 18 },{ 5, 3, 0, 5, 5, 2, 16 },{ 5, 6, 5, 4, 0, 6, 8 },{ 1, 4, 3, 3, 4, 0, 18 },{ 0, 1, 3, 0, 4, 2, 4 },{ 3, 1, 1, 1, 5, 6, 19 },{ 1, 1, 4, 5, 5, 1, 17 },{ 6, 0, 6, 5, 3, 2, 5 },{ 5, 0, 4, 5, 2, 0, 15 },{ 6, 0, 1, 0, 2, 0, 16 },{ 5, 6, 4, 4, 5, 6, 7 },{ 4, 0, 4, 3, 1, 2, 16 },{ 2, 2, 0, 0, 3, 4, 4 },{ 5, 2, 1, 2, 3, 2, 13 },{ 3, 1, 2, 6, 0, 4, 14 },{ 4, 4, 4, 1, 4, 6, 15 },{ 3, 1, 1, 5, 2, 1, 9 },{ 5, 6, 6, 1, 1, 0, 16 },{ 2, 1, 4, 3, 2, 5, 14 },{ 0, 2, 4, 4, 4, 6, 3 },{ 2, 3, 0, 3, 5, 6, 1 },{ 0, 1, 3, 3, 5, 3, 9 },{ 4, 1, 5, 5, 2, 1, 4 },{ 2, 4, 2, 3, 4, 4, 16 },{ 2, 3, 4, 2, 6, 2, 1 },{ 2, 2, 5, 0, 1, 0, 13 },{ 6, 3, 5, 1, 4, 2, 5 },{ 5, 3, 6, 0, 5, 1, 16 },{ 2, 5, 2, 4, 6, 4, 9 },{ 5, 4, 5, 6, 4, 1, 7 },{ 5, 1, 1, 2, 2, 4, 4 },{ 0, 6, 1, 3, 0, 5, 7 },{ 5, 4, 5, 1, 2, 5, 13 },{ 6, 2, 3, 3, 6, 6, 9 },{ 2, 0, 6, 0, 2, 0, 16 },{ 4, 5, 3, 2, 2, 2, 2 },{ 3, 1, 0, 6, 3, 5, 16 },{ 6, 3, 4, 3, 3, 5, 6 },{ 0, 4, 1, 2, 4, 1, 6 },{ 4, 6, 2, 2, 2, 3, 13 },{ 5, 3, 1, 6, 2, 6, 12 },{ 6, 4, 4, 3, 5, 1, 14 },{ 1, 6, 6, 6, 1, 5, 2 },{ 5, 4, 1, 3, 4, 3, 4 },{ 4, 4, 5, 0, 0, 4, 14 },{ 1, 3, 5, 0, 5, 2, 12 },{ 3, 1, 2, 2, 5, 6, 14 },{ 6, 5, 2, 4, 2, 3, 12 },{ 4, 4, 1, 0, 1, 0, 8 },{ 6, 2, 0, 0, 6, 3, 8 },{ 4, 3, 1, 6, 4, 2, 11 },{ 2, 1, 1, 6, 4, 1, 3 },{ 0, 4, 0, 2, 6, 6, 12 },{ 5, 4, 3, 5, 0, 1, 19 },{ 4, 4, 0, 6, 0, 1, 7 },{ 2, 1, 5, 2, 3, 4, 6 },{ 0, 4, 0, 5, 1, 0, 11 },{ 6, 0, 6, 4, 2, 0, 19 },{ 2, 1, 2, 6, 3, 2, 11 },{ 1, 3, 2, 1, 5, 5, 8 },{ 6, 1, 2, 4, 5, 3, 10 },{ 4, 1, 0, 3, 6, 6, 10 },{ 2, 0, 6, 4, 6, 1, 19 },{ 3, 3, 6, 2, 5, 1, 12 },{ 1, 0, 0, 0, 1, 1, 6 },{ 4, 2, 5, 1, 3, 3, 19 },{ 3, 1, 4, 5, 1, 3, 15 },{ 5, 5, 0, 6, 6, 6, 3 },{ 4, 1, 6, 5, 6, 4, 14 },{ 5, 5, 1, 2, 0, 4, 17 },{ 2, 1, 6, 3, 2, 3, 16 },{ 1, 5, 6, 6, 1, 0, 7 },{ 0, 6, 6, 5, 5, 5, 18 },{ 4, 2, 0, 2, 6, 6, 13 },{ 4, 3, 6, 6, 2, 5, 16 },{ 2, 0, 1, 1, 3, 6, 1 } };
    vector<int>needs{ 4, 4, 3, 4, 3, 2 };
    cout << a.shoppingOffers(price, special, needs);
    return 0;
}
