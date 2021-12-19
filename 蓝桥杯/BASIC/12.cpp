#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        deque<int> dq;
        vector<int> res;
        for (int i = s.size() - 1; ~i; i--) {
            int d = isdigit(s[i]) ? s[i] - '0' : s[i] - 'A' + 10;
            for (int j = 0; j < 4; j++) {
                dq.push_back(d % 2);
                d /= 2;
            }
            while (dq.size() >= 3) {
                int sum = 0;
                for (int j = 1; j <= 4; j <<= 1) {
                    sum += dq.front() * j;
                    dq.pop_front();
                }
                res.push_back(sum);
            }
        }
        int sum = 0;
        for (int i = 1; dq.size(); i <<= 1) {
            sum += dq.front() * i;
            dq.pop_front();
        }
        if (sum) {
            res.push_back(sum);
        }
        for (int i = res.size() - 1; ~i; i--) {
            cout << res[i];
        }
        cout << '\n';
    }
    return 0;
}