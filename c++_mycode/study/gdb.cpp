using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

long gdb(long a, long b) {
    if (b == 0)
        return a;
    return gdb(b, a%b);
}

void gdb(long a, long b, long d, long &x, long &y) {
    if (!b) {
        
    }

}
int main() {
    int a = 2 * 3 * 7 * 7;
    int b = 2 * 7 * 11;
    cout << gdb(a, b) << endl;
    return 0;
}