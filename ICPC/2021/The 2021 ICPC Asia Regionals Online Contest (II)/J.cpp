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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
struct R {
    double w;
    int x,y;
    R() {}
    R(double w,int x,int y):w(w),x(x),y(y) {}
    bool operator < (const R &T) const {
        return w<T.w;
    }
};
const int N=505;
const int DIR[4][2]={-1,0,1,0,0,-1,0,1};
double sum[N][N],a[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    priority_queue<R> q;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin>>a[i][j];
            q.emplace(a[i][j],i,j);
        }
    }
    while(!q.empty()) {
        auto u=q.top();
        q.pop();
        sum[u.x][u.y]+=m;
        int cnt=0;
        for(int i=0;i<4;i++) {
            int tx=u.x+DIR[i][0],ty=u.y+DIR[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&a[tx][ty]<a[u.x][u.y]) {
                ++cnt;
            }
        }
        for(int i=0;i<4;i++) {
            int tx=u.x+DIR[i][0],ty=u.y+DIR[i][1];
            if(tx>=1&&tx<=n&&ty>=1&&ty<=n&&a[tx][ty]<a[u.x][u.y]) {
                sum[tx][ty]+=sum[u.x][u.y]/cnt;
            }
        }
        if(cnt) sum[u.x][u.y]=0;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(a[i][j]==0) cout<<fixed<<setprecision(6)<<sum[i][j];
            else cout<<0;
            cout<<' ';
            if(j==n) cout<<'\n';
        }
    }
    return 0;
}