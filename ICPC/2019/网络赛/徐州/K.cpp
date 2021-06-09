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
const int N=1e3+5;
int a[N],b[N];
map<PII,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            ++mp[MP(a[i]+a[j],b[i]+b[j])];
    int res=INT_MAX;
    for(auto x:mp) res=min(res,n-x.SE);
    cout<<res<<'\n';
    return 0;
}