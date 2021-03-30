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
const int N=105;
int n,l[N],r[N],match[N*1000];
bool st[N*1000];
bool dfs(int u) {
    for(int v=r[u];v>=l[u];v--) {
        if(st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d",&n);
        int mn=0x3f3f3f3f,mx=0;
        for(int i=1;i<=n;i++) {
            scanf("%d%d",&l[i],&r[i]);
            mn=min(mn,l[i]),mx=max(mx,r[i]);
        }
        for(int i=mn;i<=mx;i++) match[i]=-1;
        int res=0;
        for(int i=n;i>=1;i--) {
            for(int j=mn;j<=mx;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d\n",res);
        VI t;
        for(int i=mn;i<=mx;i++) if(match[i]!=-1) t.PB(match[i]);
        sort(ALL(t));
        for(int i=0;i<SZ(t);i++) {
            printf("%d",t[i]);
            putchar(i==SZ(t)-1?'\n':' ');
        }
    }
    return 0;
}