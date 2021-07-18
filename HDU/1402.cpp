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
const LD PI=acos(-1);
const int N=2e5+5;
int sum[N];
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
FFT::C a[N],b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1,s2;
    while(cin>>s1>>s2) {
        int n=1<<(int)ceil(log2(SZ(s1)+SZ(s2)-1));
        for(int i=0;i<SZ(s1);i++) a[i]=FFT::C(s1[SZ(s1)-1-i]-'0',0);
        for(int i=SZ(s1);i<n;i++) a[i]=FFT::C(0,0);
        for(int i=0;i<SZ(s2);i++) b[i]=FFT::C(s2[SZ(s2)-1-i]-'0',0);
        for(int i=SZ(s2);i<n;i++) b[i]=FFT::C(0,0);
        FFT:conv(a,b,n);
        for(int i=0;i<n;i++) sum[i]=int(a[i].r+0.5);
        for(int i=0;i<n;i++) {
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
        n=SZ(s1)+SZ(s2)-1;
        while(!sum[n]&&n>0) {
            --n;
        }
        for(int i=n;~i;i--) cout<<sum[i],sum[i]=0;
        cout<<'\n';
    }
    return 0;
}