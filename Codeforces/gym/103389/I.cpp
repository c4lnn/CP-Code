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
const int N=55;
const int DIR[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
char s[N][N];
int n,m;
bool valid1(int x,int y) {
    if(x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]!='#') return true;
    return false;
}
bool valid2(int x,int y,int t) {
    if(s[x+DIR[t][0]][y]=='#'&&s[x][y+DIR[t][1]]=='#') return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=n;i++) {
        cin>>s[i]+1;
        for(int j=1;j<=m;j++) if(s[i][j]=='*') {
            x=i,y=j;
        }
    }
    int o;cin>>o;
    for(int i=1,v=0,now=0;i<=o;i++) {
        char c;cin>>c;
        if(c=='U') ++v;
        else if(c=='D') v=max(0,v-1);
        else if(c=='L') now=(now+7)%8;
        else now=(now+1)%8;
        bool f=false;
        for(int j=0;j<v;j++) {
            int tx=x+DIR[now][0],ty=y+DIR[now][1];
            if(valid1(tx,ty)&&(now&1?valid2(x,y,now):1)) x=tx,y=ty;
            else {v=0;f=true;break;}
        }
        if(f) cout<<"Crash! ";
        cout<<x<<' '<<y<<'\n';
    }
    return 0;
}