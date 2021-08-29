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
map<pair<int,int>,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        string s;cin>>s;
        mp.clear();
        LL res=0;
        int t1=0,t2=0;
        ++mp[MP(0,0)];
        for(int i=0;i<n;i++) {
            if(s[i]=='U') ++t1;
            else if(s[i]=='D') --t1;
            else if(s[i]=='L') ++t2;
            else --t2;
            res+=mp[MP(t1,t2)];
            ++mp[MP(t1,t2)];
        }
        cout<<res<<'\n';
    }
    return 0;
}