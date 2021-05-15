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
const int N=105;
int n,m,k,match[N];
bool vis[N][N],st[N];
bool dfs(int u) {
    for(int v=0;v<m;v++) {

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
    while(~scanf("%d",&n)&&n) {
        scanf("%d%d",&m,&k);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                vis[i][j]=false;
        for(int i=0;i<k;i++) {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(!b||!c) continue;
            vis[b][c]=true;
        }
        int res=0;
        for(int i=0;i<m;i++) match[i]=-1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) st[j]=false;
            if(dfs(i)) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}