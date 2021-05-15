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
const int N=505;
int n,m,match[N];
bool f[N][N],st[N];
void floyd() {
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]|=(f[i][k]&f[k][j]);
}
bool dfs(int u) {
    for(int v=1;v<=n;v++) {
        if(!f[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m)) {
        if(!n&&!m) break;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=false;
        for(int i=1;i<=m;i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            f[u][v]=true;
        }
        floyd();
        for(int i=1;i<=n;i++) match[i]=-1;
        int res=n;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) st[j]=false;
            if(dfs(i)) res--;
        }
        printf("%d\n",res);
    }
    return 0;
}