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
    int n,x,y;cin>>n>>x>>y;
    VI a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int m;cin>>m;
    VI b(m+1);
    for(int i=1;i<=m;i++) cin>>b[i];
    bool l=false,r=false;
    if(x-m<1) l=true;
    else for(int i=1;i<=m;i++) if(a[x-i]!=b[i]) {
        l=true;
        break;
    }
    if(x+m>n) r=true;
    else for(int i=1;i<=m;i++) if(a[x+i]!=b[i]) {
        r=true;
        break;
    }
    if(!l&&!r) cout<<"Unsure\n";
    else if(x<y) cout<<(!r?"Right":"Wrong")<<'\n';
    else if(x>y) cout<<(!l?"Right":"Wrong")<<'\n';
    return 0;
}