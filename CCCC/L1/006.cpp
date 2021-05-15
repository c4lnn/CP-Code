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
LL fac[20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL x;cin>>x;
    LL mx=0,l;
    for(LL i=2;i*i<=x;i++) if(x%i==0) {
        LL j=i,t=x;
        for(;j>1&&t%j==0;t/=j,j--) {}
        if(i-j>mx) mx=i-j,l=j+1;
    }
    if(!mx) mx=1,l=x;
    cout<<mx<<'\n';
    for(LL i=l;i<l+mx;i++) cout<<i<<"*\n"[i==l+mx-1];
    return 0;
}