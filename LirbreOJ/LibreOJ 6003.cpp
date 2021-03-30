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
const int N=4000;
int n,match[N],nxt[N];
bool st[N];
VI g[N];
map<int,bool> mp;
bool dfs(int u) {
    for(auto v:g[u]) {
        if(st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            nxt[u]=v;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) mp[i*i]=true;
    int res=0,mx;
    for(int i=1;;i++) {
        for(int j=i-1;j>=1;j--) {
            if(mp.count(i+j)) {
                g[i].PB(j);
            }
        }
        for(int j=1;j<=i;j++) st[j]=false;
        match[i]=-1;
        res++;
        res-=dfs(i);
        if(res>n) break;
        mx=i;
    }
    printf("%d\n",mx);
    for(int i=1;i<=mx;i++) {
        if(match[i]==-1) {
            VI x;
            for(int u=i;u;u=nxt[u]) {
                x.PB(u);
            }
            for(int i=SZ(x)-1;i>=0;i--) {
                printf("%d%c",x[i],!i?'\n':' ');
            }
        }
    }
    return 0;
}