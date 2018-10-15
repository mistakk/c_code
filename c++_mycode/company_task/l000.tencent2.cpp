using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

int main() {
    int n = 100;
    vector<bool> prim(n, true);
    prim[0] = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j*j <= i; ++j) {
            if (i%j == 0) {
                prim[i] = false;
                break;
            }
        }
    }

    return 0;

}