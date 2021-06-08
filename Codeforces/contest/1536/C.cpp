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
map<PII,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        mp.clear();
        int n;cin>>n;
        int a=0,b=0,cnt=0;
        for(int i=1;i<=n;i++) {
            char c;cin>>c;
            if(c=='D') ++a;
            else ++b;
            if(!a||!b) {
                ++cnt;
                cout<<cnt<<" \n"[i==n];
            }
            else {
                int d=__gcd(a,b);
                cout<<++mp[MP(a/d,b/d)]<<" \n"[i==n];
            }
        }
    }
    return 0;
}