#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
const int q[]={-1,1,0,0,2,10,4,40,92,352,724,2680,14200,73712};
ll f[100];
vector<pii>pf;
int cnt;
void get_f() {
    f[1]=f[2]=1;
    for(int i=3;;i++) {
        f[i]=f[i-1]+f[i-2];
            if(f[i]>1e18){cnt=i;break;}
    }
}
ll calc(ll x,ll y,ll tot) {
    ll t=0;
    while(x) t+=x/y,x/=y;
    return t/tot;
}
ll solve(ll x,ll m) {
    ll res=1e18;
    for(ll i=2;i*i<=m;i++) {
        ll tot=0;
        if(m%i==0) {
	    while(m%i==0) tot++,m/=i;
	    res=min(res,calc(x,i,tot));
	}
    }
    if(m>1) res=min(res,calc(x,m,1));
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    get_f();
    ll x,m;
    cin>>x>>m;
    for(int i=1;i<=cnt;i++) if(f[i]==x){cout<<solve(x,m)<<endl;return 0;}
    cout<<q[x%min(m,13ll)+1]<<endl;
    return 0;
}