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
const int N=2e7+10;
int mn[N];
VI p;
void prime_seive(int n) {
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prime_seive(2e7+5);
    VI a;
    for(int i=1;i<=1e7+1;i++) if(mn[i+i+1]==i+i+1) a.PB(i);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        if(n>0) {
            if(mn[n]==n) cout<<1<<'\n';
            else if(mn[n+n-1]==n+n-1||mn[n+n+1]==n+n+1) cout<<2<<'\n';
            else cout<<min(*lower_bound(ALL(p),n)*2,*lower_bound(ALL(a),n)*2+1)<<'\n';
        }
        else if(n==0) cout<<3<<'\n';
        else {
            n=-n;
            cout<<min(*lower_bound(ALL(p),n+1)*2,*lower_bound(ALL(a),n+1)*2+1)<<'\n';
        }
    }
    return 0;
}