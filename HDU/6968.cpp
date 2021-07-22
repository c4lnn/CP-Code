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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
int g[51][501],f[51][4][501];
VPII a[51];
unordered_map<string,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++) {
            string s;cin>>s;
            mp[s]=i;
            a[i].clear();
        }
        int m;cin>>m;
        for(int i=1;i<=m;i++) {
            string s;cin>>s;
            int x,y;cin>>x>>y;
            a[mp[s]].EB(x,y);
        }
        int t,p;cin>>t>>p;
        memset(g,0xc0,sizeof g);
        for(int i=1;i<=n;i++) {
            g[i][0]=0;
            for(int j=0;j<SZ(a[i]);j++) {
                for(int k=t;k>=a[i][j].SE;k--) if(g[i][k-a[i][j].SE]>=0) {
                    g[i][k]=max(g[i][k],min(100,g[i][k-a[i][j].SE]+a[i][j].FI));
                }
            }
        }
        memset(f,0xc0,sizeof f);
        f[0][0][0]=0;
        for(int i=1;i<=n;i++) {
            for(int j=0;j<=min(i,p);j++) {
                for(int k=0;k<=t;k++) {
                    for(int l=0;k-l>=0;l++) {
                        if(g[i][l]>=60&&f[i-1][j][k-l]>=0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k-l]+g[i][l]);
                        else if(j&&f[i-1][j-1][k-l]>=0) f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-l]+g[i][l]);
                    }
                }
            }
        }
        int res=-1;
        for(int i=0;i<=p;i++) {
            for(int j=0;j<=t;j++) {
                res=max(res,f[n][i][j]);
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}