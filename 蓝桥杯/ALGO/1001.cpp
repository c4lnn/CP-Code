#include <bits/stdc++.h>
using namespace std;
const int DIR[8][2] = {-2, -1, -2, 1, 2, -1, 2, 1, 1, -2, 1, 2,-1, -2, -1, 2};
int f[10][10];
int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    memset(f, -1, sizeof f);
    f[a][b] = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(a, b));
    while (q.size()) {
        pair<int,int> u = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int tx = u.first + DIR[i][0], ty = u.second + DIR[i][1];
            if (tx >= 1 && tx <= 8 && ty >= 1 && ty <= 8 && f[tx][ty] == -1) {
                f[tx][ty] = f[u.first][u.second] + 1;
                q.push(make_pair(tx, ty));
            }
        }
    }
    cout << f[c][d] << '\n';
    return 0;
}