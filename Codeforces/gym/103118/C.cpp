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
VPII e;
int t=1;
void dfs(int rt,LL k) {
    if(k<=2) return;
    if(k&1) {
        --k;
        while(k%2==0) e.EB(rt,++t),k/=2;
        if(k>2) e.EB(rt,++t);
        dfs(t,k);
    }
    else {
        e.EB(rt,++t);
        dfs(t,k-1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;cin>>n;
    dfs(1,n);
    cout<<t<<'\n';
    for(auto x:e) cout<<x.FI<<' '<<x.SE<<'\n';
    return 0;
}
