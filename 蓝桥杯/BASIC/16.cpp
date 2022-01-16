#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
int mn[N];
vector<int> p;
void pirme_seive(int n) {
    for (int i = 2; i <= n; i++) {
        if (!mn[i]) {
            mn[i] = i;
            p.push_back(i);
        }
        for (int j = 0; j < p.size(); j++) {
            int x = p[j];
            if(x > mn[i] || i * x > n) {
                break;
            }
            mn[i * x] = x;
        }
    }
}
int main() {
    int a, b;
    cin >> a >> b;
    pirme_seive(b);
    for (int i = a; i <= b; i++) {
        vector<int> f;
        int t = i;
        for (int j = 0; t > 1; j++) {
            while(t % p[j] == 0) {
                f.push_back(p[j]);
                t /= p[j];
            }
        }
        cout << i << '=';
        for (int j = 0; j < f.size(); j++) {
            cout << f[j] << "*\n"[j == f.size() - 1];
        }
    }
    return 0;
}