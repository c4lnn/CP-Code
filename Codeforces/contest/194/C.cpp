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
const int N=55;
int n,m;
bool st[N][N];
char s[N][N];
void dfs(int x,int y) {
    st[x][y]=true;
    for(int i=0;i<4;i++) {
        int tx=x+DIR[i][0],ty=y+DIR[i][1];
        if(tx>=0&&tx<n&&ty>=0&&ty<m&&s[tx][ty]=='#'&&!st[tx][ty]) {
            dfs(tx,ty);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int tot=0;
    for(int i=0;i<n;i++) {
        cin>>s[i];
        for(int j=0;j<m;j++) if(s[i][j]=='#') ++tot;
    }
    if(tot<3) return cout<<-1<<'\n',0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) if(s[i][j]=='#') {
            s[i][j]='.';
            for(int ii=0;ii<n;ii++) {
                for(int jj=0;jj<m;jj++) {
                    st[ii][jj]=false;
                }
            }
            int cnt=0;
            for(int ii=0;ii<n;ii++) {
                for(int jj=0;jj<m;jj++) if(s[ii][jj]=='#'&&!st[ii][jj]) {
                    ++cnt;
                    if(cnt==2) return cout<<1<<'\n',0;
                    dfs(ii,jj);
                }
            }
            s[i][j]='#';
        }
    }
    cout<<2<<'\n';
    return 0;
}