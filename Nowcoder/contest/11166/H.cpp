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
const int N=5e5+1;
namespace NTT {
   const LL G=3,MOD=998244353;
   LL qpow(LL a,LL b) {
       LL ret=1;
       while(b) {
           if(b&1) ret=ret*a%MOD;
           a=a*a%MOD;
           b>>=1;
       }
       return ret;
   }
    void NTT(LL x[],int n,int on) {
        VI rev(n);
        for(int i=0;i<n;i++) {
            rev[i]=rev[i>>1]>>1|(i&1?n>>1:0);
            if(i<rev[i]) swap(x[i],x[rev[i]]);
        }
        for(int mid=1;mid<n;mid<<=1) {
            LL wn=qpow(on==1?G:qpow(G,MOD-2),(MOD-1)/(mid<<1));
            for(int i=0;i<n;i+=(mid<<1)) {
                LL w=1;
                for(int j=0;j<mid;j++,w=w*wn%MOD) {
                    LL t1=x[i+j],t2=w*x[i+j+mid]%MOD;
                    x[i+j]=(t1+t2)%MOD,x[i+j+mid]=(t1-t2+MOD)%MOD;
                }
            }
        }
        if(on==-1) {
            LL inv=qpow(n,MOD-2);
            for(int i=0;i<n;i++) x[i]=x[i]*inv%MOD;
        }
    }
    void conv(LL a[],LL b[],int n) {
        NTT(a,n,1);
        NTT(b,n,1);
        for(int i=0;i<n;i++) a[i]=a[i]*b[i]%MOD;
        NTT(a,n,-1);
    }
}
LL a[N*4+5],b[N*4+5];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        a[x]=1;
        b[N-x]=1;
    }
    int len=1<<int(ceil(log2(N+N+1)));
    NTT::conv(a,b,len);
    for(int i=1;i<=N;i++) {
        bool f=false;
        for(int j=i;j<=N;j+=i) if(a[j+N]!=0) {
            f=true;
            break;
        }
        if(!f) return cout<<i<<'\n',0;
    }
    return 0;
}