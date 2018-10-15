using namespace std;
#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>

#include <fstream>

//
//Alice plays the following game, loosely based on the card game "21".
//
//Alice starts with 0 points, and draws numbers while she has less than K points.During each draw, 
//she gains an integer number of points randomly from the range[1, W], where W is an integer.Each draw is independent and the outcomes have equal probabilities.
//
//Alice stops drawing numbers when she gets K or more points.What is the probability that she has N or less points ?
//
//Example 1 :
//
//	Input : N = 10, K = 1, W = 10
//	Output : 1.00000
//	Explanation : Alice gets a single card, then stops.
//	Example 2 :
//
//	Input : N = 6, K = 1, W = 10
//	Output : 0.60000
//	Explanation : Alice gets a single card, then stops.
//	In 6 out of W = 10 possibilities, she is at or below N = 6 points.
//	Example 3 :
//
//	Input : N = 21, K = 17, W = 10
//	Output : 0.73278

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || W + K <= N + 1)
            return 1.0;
        vector<double>dp(K + W, 0);
        dp[0] = 1;
        for (int i = 0; i < K; i++) {
            for (int j = 1; j <= W; j++) {
                dp[i + j] += dp[i] / W;
            }
            dp[i] = 0;
        }
        double res = 0;
        for (int i = N + 1; i < W + K; i++)
            res += dp[i];
        return 1 - res;
    }


    double new21Game2(int N, int K, int W) {
        if (K == 0 || N >= K + W)
            return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;//Wsum为累计到目前点的概率
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i < K)
                Wsum += dp[i];
            else
                res += dp[i];
            if (i - W >= 0)
                Wsum -= dp[i - W];//前面的点对这个点无增益，要减去
        }
        return res;
    }

    double new21Game3(int N, int K, int W) {
        if (N >= K + W || K == 0)
            return 1.0;
        vector<double>dp(K + W);
        double res = 1.0;
        dp[0] = 1;
        for (int i = 0; i <= K - 1; i++) {
            for (int j = 1; j <= W; j++) {
                dp[i + j] += 1.0 / W * dp[i];
            }
            dp[i] = 0;
        }
        for (int i = N + 1; i < K + W; i++)
            res -= dp[i];
        return res;
    }
    double new21Game4(int N, int K, int W) {
        if (N >= K + W || K == 0)
            return 1.0;
        double res = 0, sumval = 1.0;
        vector<double>dp(N + 1);
        for (int i = 1; i <= N; i++) {
            dp[i] += sumval / W;
            if (i >= K)
                res += dp[i];
            else
                sumval += dp[i];
            if (i - W >= 0)
                sumval -= dp[i - W];
        }
        return res;
    }
};

int main() {
    Solution a;
    cout << a.new21Game3(21, 17, 10) << endl;
    return 0;
}