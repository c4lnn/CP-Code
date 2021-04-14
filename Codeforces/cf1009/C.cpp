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
    LL n;
    int m;
    cin>>n>>m;
    LL mx=(n-1)*n/2;
    LL mn=(n&1?(n-1)/2*((n-1)/2+1):(n/2)*(n/2));
    LL res=0;
    for(int i=1;i<=m;i++) {
        LL x,d;
        cin>>x>>d;
        res+=n*x+d*(d<0?mn:mx);
    }
    printf("%.15f\n",1.0*res/n);
    return 0;
}