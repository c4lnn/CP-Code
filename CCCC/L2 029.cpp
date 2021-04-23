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
int l,r,cnt[N];
bool st[N],vis[N],no[N];
VI p;
int get(int x) {
    int ret=0;
    while(x) {
        ret+=(x%10)*(x%10);
        x/=10;
    }
    return ret;
}
int dfs(int x,int pre,int tot) {
    if(x==1) return tot;
    if(st[x]) return -1;
    st[x]=true;
    vis[x]=true;
    int ret=dfs(get(x),x,tot+1);
    st[x]=false;
    if(ret==-1) return -1;
    if(pre<l||pre>r&&cnt[x]==-1) cnt[x]=ret-tot;
    else cnt[x]=0;
    return ret;
}
void prime_sieve(int n) {
    for(int i=2;i<=n;i++) {
        if(!no[i]) p.PB(i);
        for(auto x:p) {
            if(i*x>n) break;
            no[i*x]=true;
            if(i%x==0) break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>l>>r;
    memset(cnt,-1,sizeof cnt);
    for(int i=l;i<=r;i++) if(!vis[i]) {
        dfs(i,0,1);
    }
    prime_sieve(r);
    bool f=false;
    for(int i=l;i<=r;i++) if(cnt[i]>0) {
        f=true;
        cout<<i<<' '<<cnt[i]*(no[i]?1:2)<<'\n';
    }
    if(!f) cout<<"SAD"<<'\n';
    return 0;
}