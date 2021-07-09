#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const int MOD=998244353;
const int N=3e6+5;
int a,b,c,d,x,y,sum[N];
vector<pii> p[2];
int qpow(int a,int b,int m) {
    int ret=1;
    while(b) {
        if(b&1) ret=ret*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ret;
}
void get_factor(int x,vector<pii> &v) {
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) {
            int tot=0;
            while(x%i==0) {
                tot++;
                x/=i;
            }
            v.pb(mp(i,tot));
        }
    }
    if(x>1) v.pb(mp(x,1));
}
signed main() {
    scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&x,&y);
    get_factor(x,p[0]);
    get_factor(y,p[1]);
    int res=1;
    for(int i=0,j=0;i<p[0].size()&&j<p[1].size();i++,j++) {
        if(p[0][i].fi!=p[1][j].fi) {
            if(p[0][i].fi<p[1][j].fi) j--;
            else i--;
        }
        else {
            int tot=0;
            for(int k=c;k<=d;k++) sum[k]=(sum[k-1]+p[1][j].se*k)%(MOD-1);
            for(int k=a;k<=b;k++) {
                int t=k*p[0][i].se;
                int x=t/p[1][j].se;
                if(d<=x) tot=(tot+sum[d])%(MOD-1);
                else if(c>x) tot=(tot+(d-c+1)*t%(MOD-1))%(MOD-1);
                else tot=((tot+sum[x])%(MOD-1)+(d-x)*t%(MOD-1))%(MOD-1);
            }
            res=res*qpow(p[0][i].fi,tot,MOD)%MOD;
        }
    }
    printf("%lld\n",res);
    return 0;
}