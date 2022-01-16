#include <bits/stdc++.h>
using namespace std;
const string S[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
const string T[] = {"", "shi", "bai", "qian"};
int main() {
    int n;
    cin >> n;
    if (n == 0) {
        return cout << "ling" << '\n', 0;
    }
    vector<string> res;
    for (int i = 0, j = 0; n; i++, j++, n /= 10) {
        int d = n % 10;
        if (j == 4) {
            res.push_back("wan");
            i -= 4;
        } else if (j == 8) {
            res.push_back("yi");
            i -= 4;
        }
        if (!d) {
            if (i) {
                res.push_back("ling");
            }
            while (n % 100 == 0) {
                i++;
                j++;
                n /= 10;
            }
        } else if (i < 4) {
            if (i) {
                res.push_back(T[i % 4]);
            }
            if (n != 1 || j % 4 != 1) {
                res.push_back(S[d]);
            }
        }
    }
    for (int i = res.size() - 1; ~i; i--) {
        cout << res[i] << " \n"[!i];
    }
    return 0;
}