#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> m(n);
    vector<vector<int>> res(n);
    for (int i = 0; i < n; i++) {
        cin >> m[i];
        m[i] *= 10;
    }
    int t = n, cnt = n == 1 ? -1 : 0;
    while (t) {
        for (int i = 0; i < n; i++) {
            if (m[i]) {
                res[i].push_back(cnt += 1 + (t == 1));
                if (--m[i] == 0 && --t == 1) {
                    --cnt;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << '#' << i + 1 << '\n';
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " \n"[j % 10 == 9];
        }
    }
    return 0;
}