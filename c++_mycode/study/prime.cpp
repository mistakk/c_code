using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

bool prime_check(int n) {
    for (int i = 1; i*i <= n; i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}
int main() {
    int a = 2 * 3 * 7 * 7;
    int b = 2 * 7 * 11;
    cout << gdb(a, b) << endl;
    return 0;
}