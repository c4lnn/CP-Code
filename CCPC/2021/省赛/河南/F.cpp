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
const int N=1e3+5;
char s[N][N];
int tot[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    int x,y,xx,yy;
    for(int i=1;i<=n;i++) {
        cin>>(s[i]+1);
        for(int j=1;j<=m;j++) if(s[i][j]=='#') xx=i,yy=j;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) if(s[i][j]=='*'&&(s[i-1][j]=='*'||s[i+1][j]=='*')&&(s[i][j-1]=='*'||s[i][j+1]=='*')) {
            x=i,y=j;
        }
    }
    cout<<yy-y<<' '<<x-xx<<'\n';
    return 0;
}