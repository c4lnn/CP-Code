#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }
    int res = 0;
    while (q.size() > 1) {
        int t = q.top();
        q.pop();
        t += q.top();
        res += t;
        q.pop();
        q.push(t);
    }
    cout << res << '\n';
    return 0;
}