#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const ll mod=998244353;
const int N=2e5+5;
ll fac[N],inv[N];
ll ksm(ll a,int b) {
    ll res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll catalan(int a) {
    return (fac[a+a]*inv[a]%mod*inv[a]%mod+mod-fac[a+a]*inv[a+1]%mod*inv[a-1]%mod)%mod;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fac[0]=1;
    for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%mod;
    inv[N]=ksm(fac[N],mod-2);
    for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
    int T;cin>>T;
    for(int i=1;i<=T;i++) {
        int n;
        cin>>n;
        cout<<"Case #"<<i<<": "<<(catalan(n)+mod-catalan(n-1))%mod<<endl;
    }
    return 0;
}