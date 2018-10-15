#include <vector>
#include <iostream>
using namespace std;

//14.25 - 14.53

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}
class Solution {
public:
    //1 <= N <= 10 ^ 9
    //2 <= A <= 40000
    //2 <= B <= 40000
    int mod = 1000000007;
    int nthMagicalNumber(int N, int A, int B) {
        long long gc = A * B / gcd(A, B);
        long long  loop = gc / A + gc / B - 1;
        int mod_n = N % loop;
        

        loop = (gc * (N / loop)) % mod;


        int start_x = 0;
        int start_y = 0;
        for (int i = 0; i < mod_n; i++) {
            if (start_x + A < start_y + B)
                start_x += A;
            else
                start_y += B;
        }
        if (start_x > start_y)
            loop = (loop + start_x) % mod;
        else 
            loop = (loop + start_y) % mod;
        return loop;
    }
};
int main() {
    Solution a;
    cout<<a.nthMagicalNumber(8, 2, 3);
    return 0;
}