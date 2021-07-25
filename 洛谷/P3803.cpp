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
const int N=4e6+5;
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
            rev[i]=rev[i>>1]>>1|(i&1?n>>1:0);
            if(i<rev[i]) swap(x[i],x[rev[i]]);
        }
        for(int mid=1;mid<n;mid<<=1) {
            C wn(cos(PI/mid),sin(on*PI/mid));
            for(int i=0;i<n;i+=(mid<<1)) {
                C w(1,0);
                for(int j=0;j<mid;j++,w=w*wn) {
                    C t1=x[i+j],t2=w*x[i+j+mid];
                    x[i+j]=t1+t2,x[i+j+mid]=t1-t2;
                }
            }
        }
        if(on==-1) for(int i=0;i<n;i++) x[i].r/=n;
    }
    void conv(C a[],C b[],int n) {
        FFT(a,n,1);
        FFT(b,n,1);
        for(int i=0;i<n;i++) a[i]=a[i]*b[i];
        FFT(a,n,-1);
    }
}
FFT::C a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>a[i].r;
    for(int i=0;i<=m;i++) cin>>b[i].r;
    int len=1<<(int)ceil(log2(n+m+1));
    FFT:conv(a,b,len);
    for(int i=0;i<=n+m;i++) cout<<int(a[i].r+0.5)<<" \n"[i==n+m];
    return 0;
}