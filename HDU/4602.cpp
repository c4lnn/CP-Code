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
const int N=4e5+5;
const LD PI=acos(-1);
namespace FFT {
    struct C {
        LD r,i;
        C(LD r=0,LD i=0):r(r),i(i) {}
        C operator + (const C &T) const {
            return C(r+T.r,i+T.i);
        }
        C operator - (const C &T) const {
            return C(r-T.r,i-T.i);
        }
        C operator * (const C &T) const {
            return C(r*T.r-i*T.i,r*T.i+i*T.r);
        }
    };
    void FFT(C x[],int n,int on) {
        VI rev(n);
        for(int i=0;i<n;i++) {
            rev[i]=(rev[i>>1]>>1);
            if(i&1) rev[i]|=n>>1;
            if(i<rev[i]) swap(x[i],x[rev[i]]);
        }
        for(int i=1;i<=n;i<<=1) {
            C wn(cos(2*PI/i),sin(on*2*PI/i));
            for(int j=0;j<n;j+=i) {
                C w(1,0);
                for(int k=j;k<j+i/2;k++,w=w*wn) {
                    C t1=x[k],t2=w*x[k+i/2];
                    x[k]=t1+t2,x[k+i/2]=t1-t2;
                }
            }
        }
        if(on==-1) {
            for(int i=0;i<n;i++) {
                x[i].r/=n;
            }
        }
    }
    void conv(C a[],C b[],int n) {
        FFT(a,n,1);
        FFT(b,n,1);
        for(int i=0;i<n;i++) a[i]=a[i]*b[i];
        FFT(a,n,-1);
    }
}
int x[N];
LL sum[N];
FFT::C a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        int len=1<<(int)ceil(log2(n+n+1));
        for(int i=0;i<len;i++) a[i]=b[i]=FFT::C(0,0);
        for(int i=1;i<=n;i++) {
            cin>>x[i];
            ++a[x[i]].r;
        }
        for(int i=1;i<=n;i++) b[i]=a[i];
        FFT:conv(a,b,len);
        for(int i=1;i<=n<<1;i++) a[i].r+=0.5;
        for(int i=1;i<=n;i++) --a[x[i]+x[i]].r;
        for(int i=1;i<=n<<1;i++) a[i].r/=2;
        sort(x+1,x+1+n);
        for(int i=1;i<=n<<1;i++) sum[i]=sum[i-1]+a[i].r;
        LL res=0;
        for(int i=1;i<=n;i++) res+=(sum[n<<1]-sum[x[i]])-(n-1)-1ll*(i-1)*(n-i)-(n-i-1)-1ll*(n-i-1)*(n-i-2)/2;
        cout<<fixed<<setprecision(7)<<1.0*res/(1ll*n*(n-1)*(n-2)/6)<<'\n';
    }
    return 0;
}