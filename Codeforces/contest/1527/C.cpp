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
const int N=1e5+5;
unordered_map<int,LL> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        mp.clear();
        LL res=0;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            res+=mp[x]*(n-i+1);
            mp[x]+=i;
        }
        cout<<res<<'\n';
    }
    return 0;
}