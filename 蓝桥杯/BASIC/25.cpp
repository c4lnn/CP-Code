#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int a[N][N];
bool vis[N][N];
int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> res;
    int len = (min(n, m) + 1) / 2;
    for (int i = 1; i <= len; i++) {
        int x = i - 1, y = i;
        while (x + 1 <= m && !vis[x + 1][y]) {
            res.push_back(a[++x][y]);
            vis[x][y] = true;
        }
        while (y + 1 <= n && !vis[x][y + 1]) {
            res.push_back(a[x][++y]);
            vis[x][y] = true;
        }
        while (x - 1 >= 1 && !vis[x - 1][y]) {
            res.push_back(a[--x][y]);
            vis[x][y] =  true;
        }
        while (y - 1 >= 1 && !vis[x][y - 1]) {
            res.push_back(a[x][--y]);
            vis[x][y] = true;
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " \n"[i + 1 == res.size()];
    }
    return 0;
}