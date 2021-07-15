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
const int N=105;
int v[N];
DB p[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++) {
        char c;cin>>c;
        if(c=='D') v[i]=16;
        else if(c=='C') v[i]=24;
        else if(c=='B') v[i]=54;
        else if(c=='A') v[i]=80;
        else if(c=='S') v[i]=10000;
        v[i]-=23;
        cin>>p[i];
    }
    DB res=0;
    for(int i=1;i<=n;i++) {
        res+=p[i]*v[i];
    }
    cout<<fixed<<setprecision(4)<<res*k<<'\n';
    return 0;
}