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
const LL MOD=1e9+7;
int cnt[30000],t[30000];
bool f[30000],tf[30000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    LL res=0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        for(int j=1000;j<=21000;j++) if(f[j]) {
            t[j+x]=(t[j+x]+cnt[j])%MOD;
            t[j-x]=(t[j-x]+cnt[j])%MOD;
            tf[j+x]=tf[j-x]=true;
        }
        t[x+11000]=(t[x+11000]+1)%MOD;
        t[-x+11000]=(t[-x+11000]+1)%MOD;
        tf[x+11000]=tf[-x+11000]=true;
        res=(res+t[11000])%MOD;
        for(int j=1000;j<=21000;j++) {
            cnt[j]=t[j],t[j]=0;
            f[j]=tf[j],tf[j]=false;
        }
    }
    cout<<res<<'\n';
    return 0;
}