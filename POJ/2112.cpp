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
const int N=300;
int n,m,cap,cnt[N],match[N][N],dist[N][N];
bool st[N];
void floyd() {
    for(int k=1;k<=n+m;k++)
        for(int i=1;i<=n+m;i++)
            for(int j=1;j<=n+m;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
}
bool dfs(int u,int t) {
    for(int v=1;v<=n;v++) {
        if(dist[u][v]>t||st[v]) continue;
        st[v]=true;
        if(cnt[v]<cap) {
            match[v][++cnt[v]]=u;
            return true;
        }
        for(int i=1;i<=cnt[v];i++)
            if(dfs(match[v][i],t)) {
                match[v][i]=u;
                return true;
            }
    }
    return false;
}
bool check(int mid) {
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=n+1;i<=n+m;i++) {
        for(int j=1;j<=n;j++) st[j]=false;
        if(!dfs(i,mid)) return false;
    }
    return true;
}
int main() {
    //freopen("E:/OneDrive/Practice/in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&cap)) {
        for(int i=1;i<=n+m;i++)
            for(int j=1;j<=n+m;j++) {
                scanf("%d",&dist[i][j]);
                if(!dist[i][j]) dist[i][j]=0x3f3f3f3f;
            }
        floyd();
        int l=0,r=0x3f3f3f3f;
        while(l<r) {
            int mid=l+r>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}