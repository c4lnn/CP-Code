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
const int sz=3;
const int N=2e5+5;
int n,m,q;
struct M {
    LL a[sz][sz];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    void init() {
        clear();
        for(int i=0;i<sz;i++) a[i][i]=1;
    }
    M operator * (const M &T) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int k=0;k<sz;k++) {
                LL t=a[i][k];
                if(!t) continue;
                for(int j=0;j<sz;j++) {
                    if(!T.a[k][j]) continue;
                    ret.a[i][j]=ret.a[i][j]+T.a[k][j]*t;
                }
            }
        return ret;
    }
}t[N],tt[N];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>t[i].a[0][0]>>t[i].a[0][1];
        t[i].a[0][2]=1;
    }
    cin>>m;
    M x1,x2,x3,x4;
    x1.a[0][1]=-1;
    x1.a[1][0]=1;
    x1.a[2][2]=1;
    x2.a[0][1]=1;
    x2.a[1][0]=-1;
    x2.a[2][2]=1;
    x3.a[0][0]=-1;
    x3.a[1][1]=1;
    x3.a[2][2]=1;
    x4.a[0][0]=1;
    x4.a[1][1]=-1;
    x4.a[2][2]=1;
    tt[0].init();
    for(int i=1;i<=m;i++) {
        int x;
        cin>>x;
        if(x==1) tt[i]=tt[i-1]*x1;
        else if(x==2) tt[i]=tt[i-1]*x2;
        else if(x==3) {
            int p;
            cin>>p;
            x3.a[2][0]=2*p;
            tt[i]=tt[i-1]*x3;
        }
        else {
            int p;
            cin>>p;
            x4.a[2][1]=2*p;
            tt[i]=tt[i-1]*x4;
        }
    }
    cin>>q;
    for(int i=1;i<=q;i++) {
        int a,b;
        cin>>a>>b;
        if(!a) {
            cout<<t[b].a[0][0]<<' '<<t[b].a[0][1]<<'\n';
        }
        else {
            M res;
            res=t[b]*tt[a];
            cout<<res.a[0][0]<<' '<<res.a[0][1]<<'\n';
        }
    }
    return 0;
}