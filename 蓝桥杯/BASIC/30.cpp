#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    vector<vector<int> > d(max(10, x + 1));
    for(int i = 0; i < 10; i++) {
        d[i].push_back(i);
    }
    for (int i = 10; i <= x; i++) {
        d[i].push_back(i % 10);
        for (int j = 0 ; j < d[i / 10].size(); j++) {
            d[i].push_back(d[i / 10][j]);
        }
    }
    vector<int> res = d[1];
    for (int i = 2; i <= x; i++) {
        vector<int> temp(res.size() + d[i].size(), 0);
        for (int j = 0; j < res.size(); j++) {
            int x = 0;
            for (int k = 0; k < d[i].size(); k++) {
                temp[j + k] += res[j] * d[i][k] + x;
                x = temp[j + k] / 10;
                temp[j + k] %= 10;
            }
            temp[j + d[i].size()] += x;
        }
        while(temp.size() && temp[temp.size() - 1] == 0) {
            temp.pop_back();
        }
        swap(res, temp);
    }
    for (int i = res.size() - 1; ~i ; i--) {
        cout << res[i];
    }
    cout << '\n';
    return 0;
}