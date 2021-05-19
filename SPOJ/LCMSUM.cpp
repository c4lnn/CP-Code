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
const int N=1e6+5;
int mn[N],phi[N];
VI p;
LL res[N];
void seive(int n) {
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,phi[i]=i-1,p.PB(i);
        for(auto x:p) {
            if(x*i>n) break;
            mn[i*x]=x;
            phi[i*x]=i%x?phi[i]*(x-1):phi[i]*x;
            if(i%x==0) break;
        }
    }
    for(int i=2;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            res[j]+=1ll*i*phi[i]/2;
        }
    }
    for(int i=1;i<=n;i++) res[i]=res[i]*i+i;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    seive(1e6);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        cout<<res[n]<<'\n';
    }
    return 0;
}