#include <bits/stdc++.h>
using namespace std;
int main() {
    int k, t = 0;
    cin >> k;
    ++k;
    string s;
    while (cin >> s) {
        if (s == "End") {
            break;
        }
        ++t;
        if(t % k == 0) {
            cout << s << '\n';
        } else {
            if (s == "ChuiZi") {
                cout << "Bu" << '\n';
            } else if (s == "JianDao") {
                cout << "ChuiZi" << '\n';
            } else {
                cout << "JianDao" << '\n';
            }
        }
    }
    return 0;
}