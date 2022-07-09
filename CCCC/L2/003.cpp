#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    vector<double> v(n), w(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        a[i] = i;
    }
    sort(a.begin(), a.end(), [&](int i, int j) {
        return w[i] * v[j] > w[j] * v[i];
    });
    double res = 0;
    for (int i = 0; i < n && d; i++) {
        if (v[a[i]] <= d) {
            d -= v[a[i]];
            res += w[a[i]];
        } else {
            res += w[a[i]] * d / v[a[i]];
            d = 0;
        }
    }
    cout << fixed << setprecision(2) << res << '\n';
    return 0;
}