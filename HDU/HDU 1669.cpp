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
const int N=1005;
int n,m,cap[N],cnt[N],match[N][N];
bool f[N][N],st[N];
bool dfs(int u) {
    for(int v=0;v<m;v++) {
        if(!f[u][v]||st[v]) continue;
        st[v]=true;
        if(cnt[v]<cap[v]) {
            match[v][++cnt[v]]=u;
            return true;
        }
        for(int i=1;i<=cnt[v];i++)
            if(dfs(match[v][i])) {
                match[v][i]=u;
                return true;
            }
    }
    return false;
}
bool check(int mid) {
    for(int i=0;i<m;i++) cap[i]=mid,cnt[i]=0;
    int res=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<m;j++) st[j]=false;
        if(dfs(i)) res++;
    }
    if(res==n) return true;
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(n==0&&m==0) break;
        for(int i=1;i<=n;i++)
            for(int j=0;j<m;j++)
                f[i][j]=false;
        for(int i=1;i<=n;i++) {
            char s[20],c;
            int x;
            scanf("%s",s);
            while(scanf("%d%c",&x,&c)) {
                f[i][x]=true;
                if(c=='\n') break;
            }
        }
        int l=0,r=n;
        while(l<r) {
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}