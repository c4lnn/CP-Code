// 三分
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
LL A,B,C,D,n;
vector<LL> g[100];
LL get(LL x,LL i) {
    return A*x*x*i+B*x*x+C*x*i*i+D*x*i;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=1e6;i++) {
        int x=i,t=0;
        while(x) t+=x%10,x/=10;
        g[t].PB(i);
    }
    int T;cin>>T;
    while(T--) {
        cin>>A>>B>>C>>D>>n;
        LL res=LLONG_MAX;
        for(int i=1;i<=54;i++) {
            LL a=A*i+B;
            int l=0,r=upper_bound(ALL(g[i]),n)-g[i].begin()-1;
            if(l>r) continue;
            if(a<=0) res=min({res,get(g[i][0],i),get(g[i][r],i)});
            else {
                while(l<r) {
                    int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
                    if(get(g[i][lmid],i)<get(g[i][rmid],i)) r=rmid-1;
                    else l=lmid+1;
                }
                res=min(res,get(g[i][l],i));
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}