#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

ll mod;
ll ksm(ll a,ll b) {
    ll res=1;
    while(b) {
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d>>mod;
    cout<<ksm(a,c*d)*ksm(b,c*d)%1<<endl;
    return 0;
}