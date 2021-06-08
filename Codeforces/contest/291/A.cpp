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
map<int,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int cnt=0;
    bool f=false;
    for(int i=0;i<n;i++) {
        int x;cin>>x;
        if(!x) continue;
        ++mp[x];
        if(mp[x]==2) ++cnt;
        else if(mp[x]==3) f=true;
    }
    cout<<(f?-1:cnt)<<'\n';
    return 0;
}