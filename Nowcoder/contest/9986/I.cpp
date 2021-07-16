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
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
// head
const int DIR[4][2]={-1,0,1,0,0,-1,0,1};
const int N=105;
int n,m,xs,ys,xt,yt,dist[N][N];
char s[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    cin>>xs>>ys>>xt>>yt;
    for(int i=1;i<=n;i++) cin>>s[i]+1;
    queue<PII> q;
    memset(dist,0x3f,sizeof dist);
    q.emplace(xs,ys);
    s[xs][ys]='#';
    dist[xs][ys]=0;
    while(SZ(q)) {
        auto u=q.front();
        q.pop();
        s[u.FI][u.SE]='#';
        for(int i=0;i<4;i++) {
            int tx=u.FI+DIR[i][0],ty=u.SE+DIR[i][1];
            if(tx<1||tx>n||ty<1||ty>m||s[tx][ty]=='#') continue;
            dist[tx][ty]=dist[u.FI][u.SE]+1;
            q.emplace(tx,ty);
        }
    }
    cout<<(dist[xt][yt]==0x3f3f3f3f?-1:dist[xt][yt]*100)<<'\n';
    return 0;
}