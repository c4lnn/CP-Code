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
const int N=1e5+5;
VI o[N];
int p[105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        int k;cin>>k;
        o[i].PB(0);
        for(int j=1;j<=k;j++) {
            int x;cin>>x;
            o[i].PB(x);
        }
    }
    int u=1;
    for(int i=1;i<=m;i++) {
        int a,b;cin>>a>>b;
        if(a==0) u=o[u][b];
        else if(a==1) {
            cout<<u<<'\n';
            p[b]=u;
        }
        else u=p[b];
    }
    cout<<u<<'\n';
    return 0;
}