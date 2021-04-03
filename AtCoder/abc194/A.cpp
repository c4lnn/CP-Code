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
    int a,b;
    cin>>a>>b;
    a+=b;
    if(a>=15&&b>=8) cout<<1<<'\n';
    else if(a>=10&&b>=3) cout<<2<<'\n';
    else if(a>=3) cout<<3<<'\n';
    else cout<<4<<'\n';
    return 0;
}