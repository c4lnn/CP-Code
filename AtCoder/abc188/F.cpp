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
//head
unordered_map<LL,LL> mp;
LL solve(LL a,LL b) {
    if(a>=b) return abs(a-b);
    if(mp[b]) return mp[b];
    if(b&1) return mp[b]=min({abs(a-b),solve(a,(b+1)>>1)+2,solve(a,(b-1)>>1)+2});
    return mp[b]=min(abs(a-b),solve(a,b>>1)+1);
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL a,b;
    cin>>a>>b;
    cout<<solve(a,b)<<'\n';
    return 0;
}