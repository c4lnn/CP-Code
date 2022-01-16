#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        ++cnt[s[i] - 'a'];
    }
    int f = 0, res = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] & 1) {
            if (!f) {
                f = 1;
            } else {
                return cout << "Impossible" << '\n', 0;
            }
        }
    }
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        int l = i, r = j;
        for (;s[i] != s[r] && r > i; r--) {
        }
        for (;s[l] != s[j] && l < j; l++) {
        }
        if (j - r <= l - i) {
            res += j - r;
            for (int k = r + 1 ;k <= j; k++) {
                swap(s[k - 1], s[k]);
            }
        } else {
            res += l - i;
            for (int k = l - 1; k >= i; k--) {
                swap(s[k], s[k + 1]);
            }
        }
    }
    cout << res << '\n';
    return 0;
}