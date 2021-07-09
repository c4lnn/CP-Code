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
const DB EPS=1e-8;
DB res=0,v;
void dfs(int tot,DB p,DB a,DB b,DB c,bool aa,bool bb) {
    if(!aa) {
        if(a-v<EPS) {
            if(!bb) dfs(tot+1,p*a,0,b+a/2,c+a/2,1,0);
            else dfs(tot+1,p*a,0,0,c+a,1,1);
        }
        else {
            if(!bb) dfs(tot+1,p*a,a-v,b+v/2,c+v/2,0,0);
            else dfs(tot+1,p*a,a-v,0,c+v,0,1);
        }
    }
    if(!bb) {
        if(b-v<EPS) {
            if(!aa) dfs(tot+1,p*b,a+b/2,0,c+b/2,0,1);
            else dfs(tot+1,p*b,0,0,c+b,1,1);
        }
        else {
            if(!aa) dfs(tot+1,p*b,a+v/2,b-v,c+v/2,0,0);
            else dfs(tot+1,p*b,0,b-v,c+v,1,0);
        }
    }
    res+=(tot+1)*p*c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        res=0;
        DB a,b,c;cin>>a>>b>>c>>v;
        dfs(0,1,a,b,c,0,0);
        cout<<fixed<<setprecision(6)<<res<<'\n';
    }
    return 0;
}