#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 1000; i <= 9999; i++) {
        int t = i;
        vector<int> d;
        while (t) {
            d.push_back(t % 10);
            t /= 10;
        }
        int len = d.size();
        bool f = false;
        for (int j = 0; j < len - 1 - j; j++) {
            if (d[j] != d[len - 1 - j]) {
                f = true;
                break;
            }
        }
        if (!f) {
            cout << i <<'\n';
        }
    }
    return 0;
}