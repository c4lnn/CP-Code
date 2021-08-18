// 树状数组维护多项式系数
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
const LL MOD=1e9+7;
const int N=1e5+5;
int n;
LL a[N],b[N],c[N];
void update(LL *a,int x,LL v) {
    for(int i=x;i<=n;i+=i&-i) a[i]=((a[i]+v)%MOD+MOD)%MOD;
}
LL query(LL *a,int x) {
    LL ret=0;
    for(int i=x;i;i-=i&-i) ret=((ret+a[i])%MOD+MOD)%MOD;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int m;cin>>n>>m;
        for(int i=1;i<=n;i++) a[i]=b[i]=c[i]=0;
        for(int i=1;i<=m;i++) {
            int o;LL p;cin>>o>>p;
            if(o==1) {
                update(c,p,1);
            }
            else if(o==2) {
                update(c,p,1-p);
                update(b,p,1);
            }
            else if(o==3){
                update(c,p,(1-p)*(1-p));
                update(b,p,2-2*p);
                update(a,p,1);
            }
        }
        for(int i=1;i<=n;i++) {
            LL res=0;
            res=(res+query(c,i))%MOD;
            res=(res+query(b,i)*i%MOD)%MOD;
            res=(res+query(a,i)*i%MOD*i%MOD)%MOD;
            cout<<res<<" \n"[i==n];
        }
    }
    return 0;
}