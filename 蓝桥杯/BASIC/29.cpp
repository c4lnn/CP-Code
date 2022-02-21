#include <bits/stdc++.h>
using namespace std;
int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int len = max(a.size(), b.size());
    while (a.size() < len) {
        a += '0';
    }
    while (b.size() < len) {
        b += '0';
    }
    vector<int> res;
    int t = 0;
    for (int i = 0; i < len; i++) {
        res.push_back((t + (a[i] - '0') + (b[i] - '0')) % 10);
        t = (t + (a[i] - '0') + (b[i] - '0')) / 10;

    }
    if (t) {
        res.push_back(t);
    }
    for (int i = res.size() - 1; ~i; i--) {
        cout << res[i];
    }
    cout << '\n';
    return 0;
}