#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int i = 100; i <= 999; i++) {
        int t = i, sum = 0;
        while (t) {
            sum += (t % 10) * (t % 10) * (t % 10);
            t /= 10;
        }
        if (sum == i) {
            cout << i <<'\n';
        }
    }
    return 0;
}