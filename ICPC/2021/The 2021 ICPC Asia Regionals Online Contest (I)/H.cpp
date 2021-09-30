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
const int N=3e4;
int a[N][3];
string o[N];
VI g[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        string s;
        for(int j=1;j<=3;j++) cin>>s;
    }
    for(int i=1;i<=m;i++) {
        int x;cin>>x;
        cin>>o[i];
        if(o[i]=="203") {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            g[a[i][0]].PB(a[i][1]);
            g[a[i][0]].PB(a[i][2]);
            g[a[i][1]].PB(a[i][0]);
            g[a[i][1]].PB(a[i][2]);
            g[a[i][2]].PB(a[i][0]);
            g[a[i][2]].PB(a[i][1]);
        }
        else {
            cin>>a[i][0]>>a[i][1];
            g[a[i][0]].PB(a[i][1]);
            g[a[i][1]].PB(a[i][0]);
        }
    }
    for(int i=1;i<=n;i++) {
        sort(ALL(g[i]));
        g[i].resize(unique(ALL(g[i]))-g[i].begin());
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int x;cin>>x;
        cout<<x<<'\n';
        if(x>=1&&x<=n) {
            cout<<'[';
            for(int j=0;j<SZ(g[x]);j++) {
                cout<<g[x][j];
                if(j==SZ(g[x])-1) cout<<"]\n";
                else cout<<',';
            }
            vector<int> res;
            cout<<'[';
            for(int j=1;j<=m;j++) {
                if(o[j]=="203") {
                    if(a[j][0]==x||a[j][1]==x||a[j][2]==x) res.PB(j);
                }
                else {
                    if(a[j][0]==x||a[j][1]==x) res.PB(j);
                }
            }
            for(int j=0;j<SZ(res);j++) {
                cout<<res[j];
                if(j==SZ(res)-1) {
                    cout<<']';
                    if(i!=q) cout<<'\n';
                }
                else cout<<',';
            }
        }
        else {
            cout<<"[]\n[]";
            if(i!=q) cout<<'\n';
        }
    }
    return 0;
}