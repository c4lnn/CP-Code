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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        map<int,int> mp;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            ++mp[x];
        }
        for(int i=1;i<=m;i++) {
            int x;cin>>x;
            mp[x]=0;
        }
        int sum=0,res=0;
        for(auto x:mp) {
            if(x.SE==0) res=max(res,sum),sum=0;
            else sum+=x.SE;
        }
        res=max(res,sum);
        if(res==0) cout<<"Impossible\n";
        else cout<<res<<'\n';
    }
    return 0;
}