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
const int N=305;
LL w[N][N],la[N],lb[N],slk[N];
int ma[N],mb[N],vb[N],pre[N];
LL km(int n) {
    for(int i=1;i<=n;i++) {
        la[i]=0xc0c0c0c0c0c0c0c0;
        lb[i]=ma[i]=mb[i]=0;
        for(int j=1;j<=n;j++) la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=0x3f3f3f3f3f3f3f3f;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            LL d=0x3f3f3f3f3f3f3f3f;
            int a=mb[b];
            vb[b]=1;
            for(int j=1;j<=n;j++)
                if(!vb[j]) {
                    LL t=la[a]+lb[j]-w[a][j];
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
    LL res=0;
    for(int i=1;i<=n;i++) res+=w[i][ma[i]];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x,y,z,v;cin>>x>>y>>z>>v;
        for(int j=1;j<=n;j++) {
            w[i][j]=-(x*x+y*y+1ll*(z+v*(j-1))*(z+v*(j-1)));
        }
    }
    cout<<-km(n)<<'\n';
    return 0;
}