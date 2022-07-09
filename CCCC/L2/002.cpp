#include <bits/stdc++.h>
using namespace std;
int main() {
    string p;
    int n;
    cin >> p >> n;
    vector<string> del, now;
    vector<bool> vis(10001);
    unordered_map<string, int> val;
    unordered_map<string, string> nxt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> val[s] >> nxt[s];
    }
    for (string i = p, pre_now = "-1", pre_del = "-1"; i != "-1"; i = nxt[i]) {
        if (vis[abs(val[i])]) {
            del.push_back(i);
            if (pre_del != "-1") {
                nxt[pre_del] = i;
            }
            pre_del = i;
        } else {
            vis[abs(val[i])] = true;
            now.push_back(i);
            if (pre_now != "-1") {
                nxt[pre_now] = i;
            }
            pre_now = i;
        }
    }
    for(int i = 0; i < now.size(); i++) {
        cout << now[i] << ' ' << val[now[i]] << ' ' << (i == now.size() - 1 ? "-1" : nxt[now[i]]) << '\n';
    }
    for(int i = 0; i < del.size(); i++) {
        cout << del[i] << ' ' << val[del[i]] << ' ' << (i == del.size() - 1 ? "-1" : nxt[del[i]]) << '\n';
    }
    return 0;
}