#include <bits/stdc++.h>
using namespace std;
int main() {
    int a;
    cin >> a;
    if (a == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> d;
    while (a) {
        d.push_back(a % 16);
        a /= 16;
    }
    for (int i = d.size() - 1; ~i; i--) {
        if (d[i] >= 10) {
            cout << (char)('A' + d[i] - 10);
        }
        else {
            cout << d[i];
        }
    }
    cout << '\n';
    return 0;
}