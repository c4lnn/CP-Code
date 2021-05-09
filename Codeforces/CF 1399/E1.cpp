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
const int N=2e5+5;
int n,s,sum;
vector<pii> G[N];
struct R {
    int val,w,cnt;
    R(){}
    R(int val,int w,int cnt):val(val),w(w),cnt(cnt){}
    bool operator <(const R &a) const {
        return val<a.val;
    }
};
priority_queue<R> q;
int dfs(int u,int fa,int w) {
    int cnt=0;
    for(auto x:G[u]) {
        int v=x.fi,w=x.se;
        if(v==fa) continue;
        cnt+=dfs(v,u,w);
    }
    if(!cnt) cnt++;
    if(w) q.push(R(w*cnt-w/2*cnt,w,cnt)),sum+=w*cnt;
    return cnt;
}
signed main() {
    int T;
    scanf("%lld",&T);
    while(T--) {
        scanf("%lld%lld",&n,&s);
        sum=0;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++) G[i].clear();
        int u,v,w;
        for(int i=1;i<n;i++) {
            scanf("%lld%lld%lld",&u,&v,&w);
            G[u].pb(mp(v,w));
            G[v].pb(mp(u,w));
        }
        dfs(1,0,0);
        int tot=0;
        if(sum>s)
            while(!q.empty()) {
                auto now=q.top();
                q.pop();
                sum-=now.val;
                tot++;
                if(sum<=s) break;
                q.push(R(now.w/2*now.cnt-now.w/2/2*now.cnt,now.w/2,now.cnt));
            }
        printf("%lld\n",tot);
    }
    return 0;
}