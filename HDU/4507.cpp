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
//head
const LL MOD=1e9+7;
struct R {
    LL cnt,sum1,sum2;
    R() {cnt=-1;}
    R(LL cnt,LL sum1,LL sum2):cnt(cnt),sum1(sum1),sum2(sum2) {}
}dp[20][10][10];
LL power[20];
VI lim;
void init() {
    power[0]=1;
    for(int i=1;i<20;i++) power[i]=power[i-1]*10%MOD;
}
R dfs(int x,int mod1,int mod2,bool b) {
    if(!x) return R(mod1&&mod2,0,0);
    if(!b&&dp[x][mod1][mod2].cnt!=-1) return dp[x][mod1][mod2];
    int mx=b?lim[x]:9;
    R ret=R(0,0,0);
    for(int i=0;i<=mx;i++) {
        if(i==7) continue;
        R t=dfs(x-1,(mod1+i)%7,(mod2*10+i)%7,b&(i==mx));
        LL y=power[x-1]*i%MOD;
        ret.cnt=(ret.cnt+t.cnt)%MOD;
        ret.sum1=(ret.sum1+t.sum1)%MOD;
        ret.sum1=(ret.sum1+y*t.cnt%MOD)%MOD;
        ret.sum2=(ret.sum2+y*y%MOD*t.cnt%MOD)%MOD;
        ret.sum2=(ret.sum2+2*y%MOD*t.sum1%MOD)%MOD;
        ret.sum2=(ret.sum2+t.sum2)%MOD;
    }
    if(!b) dp[x][mod1][mod2]=ret;
    return ret;
}
LL solve(LL x) {
    lim.clear();
    lim.PB(-1);
    while(x) lim.PB(x%10),x/=10;
    return dfs(SZ(lim)-1,0,0,true).sum2;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int T;
    cin>>T;
    LL l,r;
    while(T--) {
        cin>>l>>r;
        cout<<(solve(r)-solve(l-1)+MOD)%MOD<<'\n';
    }
    return 0;
}