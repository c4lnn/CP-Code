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
const LL MOD=998244353;
const int N=3e5+5;
LL mina[N],maxa[N],minb[N],maxb[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            mina[i]=maxa[i]=x;
        }
        for(int i=0;i<n;i++) {
            int x;cin>>x;
            minb[i]=maxb[i]=x;
        }
        for(int i=n-1;~i;i--) {
            for(int j=0;j<18;j++) if(i&(1<<j)) {
                mina[i^(1<<j)]=min(mina[i^(1<<j)],mina[i]);
                minb[i^(1<<j)]=min(minb[i^(1<<j)],minb[i]);
                maxa[i^(1<<j)]=max(maxa[i^(1<<j)],maxa[i]);
                maxb[i^(1<<j)]=max(maxb[i^(1<<j)],maxb[i]);
            }
        }
        LL res=0,mx=LLONG_MIN;
        for(int i=n-1;~i;i--) {
            mx=max({mx,maxa[i]*maxb[i],maxa[i]*minb[i],mina[i]*maxb[i],mina[i]*minb[i]});
            res=(res+mx)%MOD;
        }
        cout<<(res+MOD)%MOD<<'\n';
    }
    return 0;
}