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
const int N=1e5+5;
int c[N];
set<int> s[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        s[0].insert(c[i]);
    }
    int mx=*s[0].begin();
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        if(c[u]!=c[v]) {
            s[c[u]].insert(c[v]);
            s[c[v]].insert(c[u]);
        }
    }
    for(auto x:s[0]) if(SZ(s[x])>SZ(s[mx])) mx=x;
    cout<<mx<<'\n';
    return 0;
}