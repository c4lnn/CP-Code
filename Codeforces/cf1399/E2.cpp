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
const int N=1e5+5;
int n,s,sum;
struct E {
    int v,w,c;
    E(){}
    E(int v,int w,int c):v(v),w(w),c(c){}
};
vector<E> G[N];
vi p,q;
bool cmp(int a,int b) {
    return a>b;
}
int dfs(int u,int fa,int w,int c) {
    int sz=0;
    for(auto x:G[u]) {
        int v=x.v,w=x.w,c=x.c;
        if(v==fa) continue;
        sz+=dfs(v,u,w,c);
    }
    if(!sz) sz=1;
    sum+=sz*w;
    if(c==1) while(w*sz-w/2*sz) p.pb(w*sz-w/2*sz),w/=2;
    else while(w*sz-w/2*sz) q.pb(w*sz-w/2*sz),w/=2;
    return sz;
}
void solve() {
    p.clear(),q.clear();
    p.pb(0),q.pb(0);
    dfs(1,0,0,0);
    sort(p.begin()+1,p.end(),cmp);
    sort(q.begin()+1,q.end(),cmp);
    for(int i=2;i<(int)p.size();i++) p[i]+=p[i-1];
    for(int i=2;i<(int)q.size();i++) q[i]+=q[i-1];
    int res=0x3f3f3f3f;
    sum-=s;
    for(int i=0,j=q.size()-1;i<(int)p.size();i++) {
        bool f=false;
        while(j>=0&&p[i]+q[j]>=sum) j--,f=true;
        if(f) j++;
        if(p[i]+q[j]>=sum) res=min(res,i+j*2);
    }
    printf("%lld\n",res);
}
signed main() {
    int T;
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld%lld",&n,&s);
        sum=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<n;i++) {
            int u,v,w,c;
            scanf("%lld%lld%lld%lld",&u,&v,&w,&c);
            G[u].pb(E(v,w,c));
            G[v].pb(E(u,w,c));
        }
        solve();
    }
    return 0;
}