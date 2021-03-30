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
    int n,m;
    DB t=(1+sqrt(5))/2;
    while(cin>>n>>m) {
        if(!n&&!m) break;
        if((int)((m-n)*t)==n) cout<<0<<'\n';
        else {
            cout<<1<<'\n';
            for(int i=(m-n)*t;i<=n;i++) if((int)((m-n)*t)==i) {cout<<i<<' '<<i+m-n<<'\n';break;}
            set<PII> s;
            for(int i=m*t/(t+1);i<=n;i++) if((int)((m-i)*t)==i) {s.emplace(i,m);break;}
            for(int i=m/t+m;i<=n;i++) if((int)((i-m)*t)==m) {s.emplace(m,i);break;}
            for(int i=n*t/(t+1);i<=m;i++) if((int)((n-i)*t)==i) {s.emplace(i,n);break;}
            for(int i=n/t+n;i<=m;i++) if((int)((i-n)*t)==n) {s.emplace(n,i);break;}
            for(auto x:s) cout<<x.FI<<' '<<x.SE<<'\n';
        }
    }
    return 0;
}