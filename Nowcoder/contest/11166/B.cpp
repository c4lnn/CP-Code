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
    DB r,a,b,h;cin>>r>>a>>b>>h;
    if(b>=2*r) return cout<<"Drop"<<'\n',0;
    DB h1=b*h/(a-b);
    DB ang=atan(h1/(b/2));
    DB t=cos(ang)*r;
    cout<<"Stuck"<<'\n';
    cout<<fixed<<setprecision(10)<<r*r/t-h1<<'\n';
    return 0;
}