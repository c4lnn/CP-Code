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
    map<LL,bool> mp;
    for(LL i=2;i<=1e9;i*=4) mp[i]=true;
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        if(mp.count(n)||n%2!=0) cout<<"Bob"<<'\n';
        else cout<<"Alice"<<'\n';
    }
    return 0;
}