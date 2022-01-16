#include <bits/stdc++.h>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) {
        cout << 1 << '\n';
    } else if (s == t) {
        cout << 2 << '\n';
    } else {
        bool f = true;
        for (int i = 0; i < s.size(); i++) {
            int t1, t2;
            if (isupper(s[i])) {
                t1 = s[i] - 'A';
            } else {
                t1 = s[i] - 'a';
            }
            if (isupper(t[i])) {
                t2 = t[i] - 'A';
            } else {
                t2 = t[i] - 'a';
            }
            if (t1 != t2) {
                f = false;
                break;
            }
        }
        cout << (f ? 3 : 4) << '\n';
    }
    return 0;
}