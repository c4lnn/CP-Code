#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;

const ll mod=998244353;
const int N=1010;
ll x[N],y[N];
int main() {
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    ll res=0;
    for(int i=1;i<=n;i++) {
        cin>>x[i]>>y[i];
        for(int j=1;j<i;j++)
            res=(res+abs(x[i]-x[j])+abs(y[i]-y[j]))%mod;
    }
    cout<<res*(n-2)%mod<<endl;
    return 0;
}