#include <bits/stdc++.h>
using namespace std;
int main() {
    double x11, y11, x12, y12, x21, y21, x22, y22;
    cin >> x11 >> y11 >> x12 >> y12 >> x21 >> y21 >> x22 >> y22;
    if (x11 > x12) {
        swap(x11, x12);
    }
    if (y11 > y12) {
        swap(y11, y12);
    }
    if (x21 > x22) {
        swap(x21, x22);
    }
    if (y21 > y22) {
        swap(y21, y22);
    }
    cout << fixed << setprecision(2) << max(min(x12, x22) - max(x11, x21), 0.0) * max(min(y12, y22) - max(y11, y21), 0.0) << '\n';
    return 0;
}