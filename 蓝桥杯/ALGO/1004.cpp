#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n, res;
void dfs(int x, int len1, int len2) {
    if (x == n) {
        if (len1 == len2) {
            res = max(res, len1);
        }
        return;
    }
    dfs(x + 1, len1 + a[x], len2);
    dfs(x + 1, len1, len2 + a[x]);
    dfs(x + 1, len1, len2);
}
int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << res << '\n';
    return 0;
}