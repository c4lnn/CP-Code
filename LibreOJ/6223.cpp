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
const int N=105;
int n,k,a,b,c,s[N][N],dist[N][N][11];
bool st[N][N][11];
struct R {
    int w,x,y,t;
    R() {}
    R(int w,int x,int y,int t):w(w),x(x),y(y),t(t) {}
    bool operator < (const R &T) const {
        return w>T.w;
    }
};
int dijkstra() {
    priority_queue<R> q;
    memset(dist,0x3f,sizeof dist);
    q.emplace(0,1,1,k);
    dist[1][1][k]=0;
    while(SZ(q)) {
        auto u=q.top();
        q.pop();
        if(u.x==n&&u.y==n) return u.w;
        if(u.t==0||st[u.x][u.y][u.t]) continue;
        st[u.x][u.y][u.t]=true;
        for(int i=0;i<4;i++) {
            int tx=u.x+DIR[i][0],ty=u.y+DIR[i][1];
            if(tx<=0||tx>n||ty<=0||ty>n) continue;
            if(!s[tx][ty]) {
                if(!st[tx][ty][u.t-1]&&u.w+(i==0||i==2?b:0)<dist[tx][ty][u.t-1]) {
                    dist[tx][ty][u.t-1]=u.w+(i==0||i==2?b:0);
                    q.emplace(dist[tx][ty][u.t-1],tx,ty,u.t-1);
                }
                if(!st[tx][ty][k]&&u.w+(i==0||i==2?b:0)+c+a<dist[tx][ty][k]) {
                    dist[tx][ty][k]=u.w+(i==0||i==2?b:0)+c+a;
                    q.emplace(dist[tx][ty][k],tx,ty,k);
                }
            }
            else if(!st[tx][ty][k]&&u.w+(i==0||i==2?b:0)+a<dist[tx][ty][k]) {
                dist[tx][ty][k]=u.w+(i==0||i==2?b:0)+a;
                q.emplace(dist[tx][ty][k],tx,ty,k);
            }
        }
    }
    return 0x3f3f3f3f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>a>>b>>c;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>s[i][j];
    cout<<dijkstra()<<'\n';
    return 0;
}