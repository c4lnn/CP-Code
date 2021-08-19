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
    vector<string> a;
    for(int i=0;i<60;i++) {
        LL d=1ll<<i;
        string s="";
        while(d) {
            s+=d%10+'0';
            d/=10;
        }
        reverse(ALL(s));
        a.PB(s);
    }
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        string s="";
        while(n) {
            s+=n%10+'0';
            n/=10;
        }
        reverse(ALL(s));
        int res=100;
        for(int i=0;i<60;i++) {
            int t=0,cnt=0;
            for(int j=0;j<SZ(s);j++) {
                if(t<SZ(a[i])&&s[j]==a[i][t]) ++t;
                else ++cnt;
            }
            if(t<SZ(a[i])) cnt+=SZ(a[i])-t;
            res=min(res,cnt);
        }
        cout<<res<<'\n';
    }
    return 0;
}