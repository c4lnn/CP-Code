#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
map<vector<int>,PII> mp;
VI t[10005],tt[10005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            int x;cin>>x;
            t[i].PB(x);
        }
        if(!mp.count(t[i])) mp[t[i]].FI=i;
        ++mp[t[i]].SE;
    }
    for(auto x:mp) {
        tt[x.SE.SE].PB(x.SE.FI);
    }
    cout<<SZ(mp)<<'\n';
    for(int i=10000;~i;i--) if(SZ(tt[i])) {
        for(auto x:tt[i]) {
            cout<<mp[t[x]].SE<<' ';
            for(int j=0;j<m;j++) {
                cout<<t[x][j]<<" \n"[j==m-1];
            }
        }
    }
    return 0;
}