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
char s[105][105];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    --x,--y;
    for(int i=0;i<n;i++) cin>>s[i];
    int res=0;
    if(s[x][y]=='#') return cout<<0<<'\n',0;
    for(int i=x;~i;i--) {
        if(s[i][y]=='.') ++res;
        else break;
    }
    for(int i=x+1;i<n;i++) {
        if(s[i][y]=='.') ++res;
        else break;
    }
    for(int i=y-1;~i;i--) {
        if(s[x][i]=='.') ++res;
        else break;
    }
    for(int i=y+1;i<m;i++) {
        if(s[x][i]=='.') ++res;
        else break;
    }
    cout<<res<<'\n';
    return 0;
}