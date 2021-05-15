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
unordered_map<int,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        mp.clear();
        int n;cin>>n;
        VI a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        LL res=0;
        for(int i=n;i>=1;i--) {
            if(mp.count(a[i]-i)) res+=mp[a[i]-i];
            ++mp[a[i]-i];
        }
        cout<<res<<'\n';
    }
    return 0;
}