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
const int N=40;
const int dir[2][2]={1,0,0,1};
int n,m,match[N*N],cnt,mp[N][N];
char s[N][N];
bool f[N*N][N*N],st[N*N];
bool valid(int x,int y) {
    if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='*') return true;
    return false;
}
bool dfs(int u) {
    for(int v=1;v<=cnt;v++) {
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
    int tt;
    scanf("%d",&tt);
    while(tt--) {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(s[i][j]=='*')
                    mp[i][j]=++cnt;
        for(int i=1;i<=cnt;i++)
            for(int j=1;j<=cnt;j++)
                f[i][j]=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) {
                if(s[i][j]!='*') continue;
                for(int k=0;k<2;k++) {
                    int tx=i+dir[k][0],ty=j+dir[k][1];
                    if(valid(tx,ty)) f[mp[i][j]][mp[tx][ty]]=f[mp[tx][ty]][mp[i][j]]=true;
                }
            }
        int res=0;
        for(int i=1;i<=cnt;i++) match[i]=-1;
        for(int i=1;i<=cnt;i++) {
            for(int j=1;j<=cnt;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d\n",cnt-res/2);
    }
    return 0;
}