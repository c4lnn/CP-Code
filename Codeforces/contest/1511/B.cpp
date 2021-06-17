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
    int T;cin>>T;
    while(T--) {
        int a,b,c;cin>>a>>b>>c;
        int d=1;
        while((int)(log10(d)+1)<c) d<<=1;
        int x=d,y=d;
        while((int)(log10(x)+1)<a) x<<=1;
        while((int)(log10(y)+1)<b) y*=3;
        cout<<x<<' '<<y<<'\n';
    }
    return 0;
}
