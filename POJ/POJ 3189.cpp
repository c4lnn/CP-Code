#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <climits>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
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
const int M=25;
int n,m,f[N][M],cap[M],cnt[M],match[M][N];
bool st[M];
bool dfs(int u,int l,int r) {
    for(int i=l;i<=r;i++) {
        int v=f[u][i];
        if(st[v]) continue;
        st[v]=true;
        if(cnt[v]<cap[v]) {
            match[v][++cnt[v]]=u;
            return true;
        }
        for(int i=1;i<=cnt[v];i++)
            if(dfs(match[v][i],l,r)) {
                match[v][i]=u;
                return true;
            }
    }
    return false;
}
bool check(int l,int r) {
    for(int i=1;i<=m;i++) cnt[i]=0;
    int res=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) st[j]=false;
        if(dfs(i,l,r)) res++;
    }
    if(res==n) return true;
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            int x;
            scanf("%d",&x);
            f[i][j]=x;
        }
    for(int i=1;i<=m;i++) scanf("%d",&cap[i]);
    int l=1,r=1,res=0x3f3f3f3f;
    while(l<=r&&r<=m) {
        if(check(l,r)) res=min(res,r-l+1),l++;
        else r++;
    }
    printf("%d\n",res);
    return 0;
}