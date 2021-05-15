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
const int N=105;
int v[N],p[N],h[N],a[N],b[N];
int w[N][N],la[N],lb[N],ma[N],mb[N],vb[N],slk[N],pre[N];
int km(int n) {
    for(int i=1;i<=n;i++) {
        la[i]=0xc0c0c0c0;
        lb[i]=ma[i]=mb[i]=0;
        for(int j=1;j<=n;j++) la[i]=max(la[i],w[i][j]);
    }
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=n;j++) vb[j]=pre[j]=0,slk[j]=0x3f3f3f3f;
        int b=0,p=-1;
        for(mb[b]=i;mb[b];b=p) {
            int d=0x3f3f3f3f,a=mb[b];
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
    int n;
    while(cin>>n&&n) {
        for(int i=1;i<=n;i++) cin>>v[i];
        for(int i=1;i<=n;i++) cin>>h[i];
        for(int i=1;i<=n;i++) cin>>p[i];
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                w[i][j]=(p[j]+a[i]-1)/a[i]<=(h[i]+b[j]-1)/b[j]?v[i]:-v[i];
                w[i][j]*=n+1;
            }
        }
        for(int i=1;i<=n;i++) ++w[i][i];
        int ret=km(n);
        if(ret>0) cout<<ret/(n+1)<<' '<<fixed<<setprecision(3)<<ret%(n+1)*1.0/n*100<<'%'<<'\n';
        else cout<<"Oh, I lose my dear seaco!"<<'\n';
    }
    return 0;
}