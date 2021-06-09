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
const int N=75;
const LL MOD=1e9+7;
LL f[N<<1],a[N][N],x[N]; // a 是增广矩阵，b 是解
bool free_x[N]; // 是否为自由变量
LL qpow(LL a,LL b) {
    LL ret=1;
    while(b) {
        if(b&1) ret=ret*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ret;
}
int gauss(int n,int m) { // n 个方程，m 个变量
    memset(x,0,sizeof x);
    memset(free_x,true,sizeof free_x);
    int r=0,c=0;
    while(r<n&&c<m) {
        int R=r;
        for(int i=r+1;i<n;i++) if(a[i][c]>a[R][c]) R=i;
        if(R!=r) for(int j=c;j<=m;j++) swap(a[r][j],a[R][j]);
        if(a[r][c]==0) {++c;continue;}
        for(int i=r+1;i<n;i++) if(a[i][c]) {
            LL t=a[i][c]*qpow(a[r][c],MOD-2)%MOD;
            for(int j=c;j<=m;j++) a[i][j]=((a[i][j]-a[r][j]*t%MOD)%MOD+MOD)%MOD;
        }
        ++r,++c;
    }
    for(int i=m-1;i>=0;i--) {
        LL s=a[i][m];
        for(int j=i+1;j<m;j++) s=((s-a[i][j]*x[j]%MOD)%MOD+MOD)%MOD;
        x[i]=s*qpow(a[i][i],MOD-2)%MOD;
    }
    return 0;
}
const int sz=75;
struct M {
    LL a[sz][sz];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    M operator + (const M &T) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ret.a[i][j]=(a[i][j]+T.a[i][j])%MOD;
        return ret;
    }
    M operator * (const M &T) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int k=0;k<sz;k++) if(a[i][k])
                for(int j=0;j<sz;j++) if(T.a[k][j])
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*T.a[k][j]%MOD)%MOD;
        return ret;
    }
    M operator ^ (LL b) const {
        M ret,bas;
        for(int i=0;i<sz;i++) ret.a[i][i]=1;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                bas.a[i][j]=a[i][j];
        while(b) {
            if(b&1) ret=ret*bas;
            bas=bas*bas;
            b>>=1;
        }
        return ret;
    }
}b,c;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int k;LL n;cin>>k>>n;
        for(int i=1;i<=k<<1;i++) cin>>f[i];
        if(n<=2*k) {
            LL sum=0;
            for(int i=1;i<=n;i++) sum=(sum+f[i])%MOD;
            cout<<sum<<'\n';
        }
        else {
            for(int i=0;i<k;i++) {
                for(int j=0;j<k;j++) {
                    a[i][j]=f[i+k-j];
                }
                a[i][k]=f[k+i+1];
            }
            gauss(k,k);
            b.clear(),c.clear();
            for(int i=0;i<k;i++) b.a[0][i]=f[k+i+1];
            for(int i=1;i<=k<<1;i++) b.a[0][k]=(b.a[0][k]+f[i])%MOD;
            for(int i=0;i<=k-2;i++) c.a[i+1][i]=1;
            for(int i=0;i<k;i++) c.a[i][k-1]=c.a[i][k]=x[i];
            c.a[k][k]=1;
            b=b*(c^(n-2*k));
            cout<<b.a[0][k]<<'\n';
        }
     }
    return 0;
}