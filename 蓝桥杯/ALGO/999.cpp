#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 5218;
LL qpow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) {
            ret = ret * a % MOD;
        }
        a = a * a %MOD;
        b >>= 1;
    }
    return ret;
}
int main() {
    LL n;
    cin >> n;
    if (n <= 3) {
        cout << n  << '\n';
    } else if (n % 3 == 0) {
        cout << qpow(3, n / 3) << '\n';
    } else if (n % 3 == 1) {
        cout << qpow(3, n / 3 - 1) * 4 % MOD << '\n';
    } else {
        cout << qpow(3, n / 3) * 2 % MOD << '\n';
    }
    return 0;
}