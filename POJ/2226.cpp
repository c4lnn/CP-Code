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
const int N=55;
const int M=1300;
char s[N][N];
int n,m,t1,t2,a[M][M],b[M][M],match[M];
bool vis[M][M],st[M];
bool dfs(int u) {
    for(int v=1;v<=t2;v++) {
        if(!vis[u][v]||st[v]) continue;
        st[v]=true;
        if(match[v]==-1||dfs(match[v])) {
            match[v]=u;
            return true;
        }
    }
    return false;
}
int main() {
    //freopen("D:/Sublime Text 3/in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='*') {
                if(j==0||s[i][j-1]=='.') t1++;
                a[i][j]=t1;
            }
    for(int j=0;j<m;j++)
        for(int i=0;i<n;i++)
            if(s[i][j]=='*') {
                if(i==0||s[i-1][j]=='.') t2++;
                b[i][j]=t2;
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(s[i][j]=='*')
                vis[a[i][j]][b[i][j]]=true;
    int res=0;
    for(int i=1;i<=t2;i++) match[i]=-1;
    for(int i=1;i<=t1;i++) {
        for(int j=1;j<=t2;j++) st[j]=false;
        if(dfs(i)) res++;
    }
    printf("%d\n",res);
    return 0;
}