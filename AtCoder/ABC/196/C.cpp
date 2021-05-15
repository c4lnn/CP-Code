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
LL power[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL n;
    cin>>n;
    LL res=0;
    power[0]=1;
    for(int i=1;i<=15;i++) power[i]=power[i-1]*10;
    for(LL i=1;;i++) {
        if(i*power[(int)(log10(i))+1]+i>n) break;
        ++res;
    }
    cout<<res<<'\n';
    return 0;
}