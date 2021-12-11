#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 0; i < 32; i++) {
        for (int j = 4; ~j; j--) {
            cout << ((i >> j) & 1);
        }
        cout << '\n';
    }
    return 0;
}