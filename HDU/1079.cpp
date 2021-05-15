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
const int D[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sg[2100][15][35];
bool st[2100];
struct R {
    int y,m,d;
    R() {}
    R(int y,int m,int d):y(y),m(m),d(d) {}
};
int mex(int x,int y) {
    return x&&y?0:(x+y==1?2:1);
}
R nxt1(int y,int m,int d) {
    if(st[y]&&m==2&&d==28) return R(y,2,29);
    if(m==12&&d==31) return R(y+1,1,1);
    if(d==(st[y]&&m==2?29:D[m])) return R(y,m+1,1);
    return R(y,m,d+1);
}
R nxt2(int y,int m,int d) {
    if(st[y]&&m==1&&d>29||m<=11&&D[m+1]<d) return nxt1(y,m,d);
    if(m==12) return R(y+1,1,d);
    return R(y,m+1,d);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1900;i<=2000;i++) if(i%4==0&&i%100!=0||i%400==0) st[i]=true;
    for(int i=5;i<=30;i++) sg[2001][11][i]=1;
    for(int i=1;i<=31;i++) sg[2001][12][i]=1;
    for(int y=2001;y>=1900;y--)
        for(int m=(y==2001?11:12);m>=1;m--)
            for(int d=(st[y]&&m==2?29:(y==2001&&m==11?4:D[m]));d>=1;d--) {
                R a=nxt1(y,m,d),b=nxt2(y,m,d);
                sg[y][m][d]=mex(sg[a.y][a.m][a.d],sg[b.y][b.m][b.d]);
            }
    int T;
    cin>>T;
    while(T--) {
        int y,m,d;
        cin>>y>>m>>d;
        cout<<(sg[y][m][d]>0?"YES":"NO")<<'\n';
    }
    return 0;
}