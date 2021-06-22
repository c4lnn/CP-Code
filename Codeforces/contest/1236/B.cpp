#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod=1e9+7;

int n,m;

ll ksm(ll n,ll x)
{
    ll res=1;
    while(x)
    {
        if(x&1) res=res*n%mod;
        n=n*n%mod;
        x>>=1;
    }
    return res;
}
int main()
{
    cin>>n>>m;
    cout<<ksm((ksm(2,m)+mod-1)%mod,n);
    return 0;
}