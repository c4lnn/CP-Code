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
//head
const int DIR[4][2]={-1,0,1,0,0,-1,0,1};
const int N=11;
struct R {
    int x,y,st;
    R() {}
    R(int x,int y,int st):x(x),y(y),st(st) {}
};
int n,m,p,k,door[N][N][N][N],dist[N][N][1<<N];
VI key[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>p>>k;
    memset(door,0x3f,sizeof door);
    for(int i=1;i<=k;i++) {
        int x1,y1,x2,y2,g;
        cin>>x1>>y1>>x2>>y2>>g;
        door[x1][y1][x2][y2]=door[x2][y2][x1][y1]=g-1;
    }
    cin>>k;
    for(int i=1;i<=k;i++) {
        int x,y,q;
        cin>>x>>y>>q;
        key[x][y].PB(q-1);
    }
    queue<R> q;
    memset(dist,-1,sizeof dist);
    int t=0;
    for(auto x:key[1][1]) t|=1<<x;
    q.push(R(1,1,t));
    dist[1][1][t]=0;
    while(SZ(q)) {
        auto u=q.front();
        q.pop();
        if(u.x==n&&u.y==m) return cout<<dist[u.x][u.y][u.st]<<'\n',0;
        for(int i=0;i<4;i++) {
            int tx=u.x+DIR[i][0],ty=u.y+DIR[i][1];
            if(tx<=0||tx>n||ty<=0||ty>m) continue;
            if(door[u.x][u.y][tx][ty]==-1||door[u.x][u.y][tx][ty]!=0x3f3f3f3f&&!(u.st&(1<<door[u.x][u.y][tx][ty]))) continue;
            int st=u.st;
            for(auto x:key[tx][ty]) st|=1<<x;
            if(dist[tx][ty][st]!=-1) continue;
            dist[tx][ty][st]=dist[u.x][u.y][u.st]+1;
            q.push(R(tx,ty,st));
        }
    }
    cout<<-1<<'\n';
    return 0;
}