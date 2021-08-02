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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m;
    LL sum=0;
    int mx=0;
    VI a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
        sum+=a[i];
    }
    LL res=max(1ll*mx,(sum+m-1)/m),t=0;
    for(int i=0,id=1;i<n;i++) {
        if(res-t>=a[i]) {
            cout<<1<<' '<<id<<' '<<t<<' '<<t+a[i]<<'\n';
            t+=a[i];
            if(t==res) ++id,t=0;
        }
        else {
            cout<<2<<' '<<id+1<<' '<<0<<' '<<a[i]-res+t<<' '<<id<<' '<<t<<' '<<res<<'\n';
            ++id;
            t=a[i]-res+t;
        }
    }
    return 0;
}