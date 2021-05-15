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
const int INF=0x3f3f3f3f;
const int N=105;
int w[N][N],la[N],lb[N],ma[N],mb[N],vb[N],slk[N],pre[N];
VPII a,b;
string s[N];
int km(int n) {
    for(int i=1;i<=n;i++) {
        la[i]=-INF;
        lb[i]=ma[i]=mb[i]=0;
        for(int j=1;j<=n;j++)
            la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=INF;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            int d=INF,a=mb[b];
            vb[b]=1;
            for(int j=1;j<=n;j++)
                if(!vb[j]) {
                    int t=la[a]+lb[j]-w[a][j];
                    if(t<slk[j]) slk[j]=t,pre[j]=b;
                    if(slk[j]<d) d=slk[j],p=j;
                }
            for(int j=0;j<=n;j++) {
                if(vb[j]) la[mb[j]]-=d,lb[j]+=d;
                else slk[j]-=d;
            }
        }
        for(;b;b=pre[b]) mb[b]=mb[pre[b]],ma[mb[b]]=b;
    }
    int res=0;
    for(int i=1;i<=n;i++) res+=w[i][ma[i]];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    while(cin>>n>>m) {
        if(!n&&!m) break;
        a.clear(),b.clear();
        for(int i=0;i<n;i++) cin>>s[i];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(s[i][j]=='m') a.EB(i,j);
                else if(s[i][j]=='H') b.EB(i,j);
            }
        }
        for(int i=0;i<SZ(a);i++) {
            for(int j=0;j<SZ(b);j++) {
                w[i+1][j+1]=-(abs(b[j].FI-a[i].FI)+abs(b[j].SE-a[i].SE));
            }
        }
        cout<<-km(SZ(a))<<'\n';
    }
    return 0;
}