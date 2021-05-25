#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int DIR[4][2]={-1,0,1,0,0,-1,0,1};
const int N=15;
int n,m,a[N][N],res=INT_MAX,sum;
bool st[N][N];
void dfs(int x,int y,int tot,int t) {
    if(t==sum-t) {
        res=min(res,tot);
        return;
    }
    for(int i=0;i<4;i++) {
        int tx=x+DIR[i][0],ty=y+DIR[i][1];
        if(tx>=1&&tx<=n&&ty>=1&&ty<=m&&!st[tx][ty]) {
            st[tx][ty]=true;
            dfs(tx,ty,tot+1,t+a[tx][ty]);
            st[tx][ty]=false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>m>>n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>a[i][j];
            sum+=a[i][j];
        }
    }
    dfs(1,1,1,a[1][1]);
    cout<<(res==INT_MAX?0:res)<<'\n';
    return 0;
}