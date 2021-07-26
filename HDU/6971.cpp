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
        for(int i=0;i<18;i++) {
            for(int j=n-1;~j;j--) if(j&(1<<i)) {
                mina[j^(1<<i)]=min(mina[j^(1<<i)],mina[j]);
                minb[j^(1<<i)]=min(minb[j^(1<<i)],minb[j]);
                maxa[j^(1<<i)]=max(maxa[j^(1<<i)],maxa[j]);
                maxb[j^(1<<i)]=max(maxb[j^(1<<i)],maxb[j]);
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