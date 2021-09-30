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
const int N=5;
const LL MOD=1e9+7;
struct M {
    LL a[N][N];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    void init() {
        clear();
        for(int i=0;i<N;i++) a[i][i]=1;
    }
    M operator + (const M &T) const {
        M ret;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                ret.a[i][j]=(a[i][j]+T.a[i][j])%MOD;
        return ret;
    }
    M operator - (const M &T) const {
        M ret;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                ret.a[i][j]=(a[i][j]-T.a[i][j]+MOD)%MOD;
        return ret;
    }
    M operator * (const LL &v) const {
        M ret;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++) if(a[i][j])
                ret.a[i][j]=a[i][j]*v%MOD;
        return ret;
    }
    M operator * (const M &T) const {
        M ret;
        for(int i=0;i<N;i++)
            for(int k=0;k<N;k++) if(a[i][k])
                for(int j=0;j<N;j++) if(T.a[k][j])
                    ret.a[i][j]=(ret.a[i][j]+a[i][k]*T.a[k][j]%MOD)%MOD;
        return ret;
    }
    M operator ^ (LL b) const {
        M ret,bas;
        for(int i=0;i<N;i++) ret.a[i][i]=1;
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                bas.a[i][j]=a[i][j];
        while(b) {
            if(b&1) ret=ret*bas;
            bas=bas*bas;
            b>>=1;
        }
        return ret;
    }
    void print() {
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                cout<<a[i][j]<<" \n"[j==N-1];
    }
};
LL c[N][N]={0,1,0,0,0,
            0,0,1,0,0,
           -1,0,0,0,0,
            1,0,0,2,0,
            0,0,0,1,2};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    M b;
    memcpy(b.a,c,sizeof c);
    while(T--) {
        int n;cin>>n;
        if(n<4) cout<<0<<'\n';
        else {
            M a;
            a.a[0][3]=1;
            a.a[0][4]=2;
            cout<<((a*(b^(n-3))).a[0][0]+MOD)%MOD<<'\n';
        }
    }
    return 0;
}