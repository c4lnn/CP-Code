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
map<LL,LL> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    mp[0]=k;
    for(int i=1;i<=n;i++) {
        LL a,b;cin>>a>>b;
        mp[a]+=b;
    }
    LL t=0;
    for(auto x:mp) {
        if(t<x.FI) break;
        else t+=x.SE;
    }
    cout<<t<<'\n';
    return 0;
}