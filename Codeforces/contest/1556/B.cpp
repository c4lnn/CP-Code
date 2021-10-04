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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        VI a(n+1),odd,even;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) {
            if(a[i]&1) odd.PB(i);
            else even.PB(i);
        }
        if(abs(SZ(odd)-SZ(even))>=2) cout<<-1<<'\n';
        else {
            LL res=0x3f3f3f3f3f3f3f3f;
            if(SZ(odd)>=SZ(even)) {
                int pos=1;
                LL t=0;
                for(auto x:odd) t+=abs(x-pos),pos+=2;
                res=min(res,t);
            }
            if(SZ(even)>=SZ(odd)) {
                int pos=1;
                LL t=0;
                for(auto x:even) t+=abs(x-pos),pos+=2;
                res=min(res,t);
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}