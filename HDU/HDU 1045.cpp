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
const int N=5;
int n,cnt,match[N*N],col_x[N][N],col_y[N][N];
bool st[N*N];
char s[N][N];
VI g[N*N];
bool dfs(int u) {
    for(auto v:g[u]) {
        if(st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[u]=v;
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    while(~scanf("%d",&n)&&n) {
        for(int i=0;i<n;i++) scanf("%s",s[i]);
        cnt=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++) {
                if(j==0||s[i][j-1]=='X') cnt++;
                col_x[i][j]=cnt;
            }
        for(int j=0;j<n;j++)
            for(int i=0;i<n;i++) {
                if(i==0||s[i-1][j]=='X') cnt++;
                col_y[i][j]=cnt;
            }
        for(int i=1;i<=cnt;i++) g[i].clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(s[i][j]!='X') {
                    g[col_x[i][j]].PB(col_y[i][j]);
                    g[col_y[i][j]].PB(col_x[i][j]);
                }
        int res=0;
        for(int i=1;i<=cnt;i++) match[i]=-1;
        for(int i=1;i<=cnt;i++) {
            if(match[i]!=-1) continue;
            for(int j=1;j<=cnt;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}