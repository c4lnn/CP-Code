#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    long long n = 0;
    for (int i = s.size() - 1, power = 1; ~i; i--, power *= 16) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            n += 1LL * (s[i] - 'A' + 10) * power;
        }
        else {
            n += 1LL * (s[i] - '0') * power;
        }
    }
    cout << n << '\n';
    return 0;
}