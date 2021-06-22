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
const LL MOD=1e9+7;
int sz,m,s;
LL k;
struct M {
    LL a[105][105];
    void clear() {memset(a,0,sizeof a);}
    M() {clear();}
    void init() {
        clear();
        for(int i=0;i<sz;i++) a[i][i]=1;
    }
    M operator + (const M &T) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ret.a[i][j]=(a[i][j]+T.a[i][j])%MOD;
        return ret;
    }
    M operator - (const M &T) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                ret.a[i][j]=(a[i][j]-T.a[i][j]+MOD)%MOD;
        return ret;
    }
    M operator * (const LL &v) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++) {
                if(!a[i][j]) continue;
                ret.a[i][j]=a[i][j]*v%MOD;
            }
        return ret;
    }
    M operator * (const M &T) const {
        M ret;
        for(int i=0;i<sz;i++)
            for(int k=0;k<sz;k++) {
                LL t=a[i][k];
                if(!t) continue;
                for(int j=0;j<sz;j++) {
                    if(!T.a[k][j]) continue;
                    ret.a[i][j]=(ret.a[i][j]+T.a[k][j]*t%MOD)%MOD;
                }
            }
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
    void print() {
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                cout<<a[i][j]<<" \n"[j==sz-1];
    }
};
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>sz>>m>>k>>s;
    M t;
    for(int i=1;i<=m;i++) {
        int u,v;
        cin>>u>>v;
        ++t.a[u-1][v-1];
    }
    t=t^k;
    LL res=0;
    --s;
    for(int i=0;i<sz;i++) if(i!=s) res=(res+t.a[s][i])%MOD;
    cout<<res<<'\n';
    return 0;
}