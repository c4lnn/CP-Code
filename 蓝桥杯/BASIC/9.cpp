#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    for (int i = 10000; i <= 999999; i++) {
        int t = i, sum = 0;;
        vector<int> d;
        while (t) {
            d.push_back(t % 10);
            sum += t % 10;
            t /= 10;
        }
        if (sum != n) {
            continue;
        }
        int len = d.size();
        bool f= false;
        for (int j = 0; j < len - 1 - j; j++) {
            if (d[j] != d[len - 1 - j]) {
                f = true;
                break;
            }
        }
        if (!f) {
            cout << i << '\n';
        }
    }
    return 0;
}