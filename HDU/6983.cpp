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
unordered_map<LL,LL> mp;
LL n,k;
LL solve(LL n) {
    if(mp.count(n)) return mp[n];
    if(n<=k) return mp[n]=1;
    return mp[n]=solve(n/2)+solve(n-n/2)+1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        cin>>n>>k;
        cout<<solve(n)<<'\n';
        mp.clear();
    }
    return 0;
}