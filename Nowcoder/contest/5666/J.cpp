#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
//head
const ll mod=998244353;
const int N=1e6+5;
ll fac[N+N],infac[N];
ll ksm(ll a,int b) {
    ll res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main() {
    fac[0]=1;
    for(int i=1;i<=2000001;i++) fac[i]=fac[i-1]*i%mod;
    infac[1000000]=ksm(fac[1000000],mod-2);
    for(int i=1000000-1;i>=1;i--) infac[i]=infac[i+1]*(i+1)%mod;
    int n;
    while(~scanf("%d",&n)) {
        printf("%lld\n",ksm(fac[2*n+1]*infac[n]%mod*infac[n]%mod,mod-2));
    }
    return 0;
}