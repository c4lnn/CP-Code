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
    int n;cin>>n;
    int mn,mx;
    if(n%7==0) mn=mx=n/7*2;
    else if(n%7==6) mn=n/7*2+1,mx=n/7*2+2;
    else mn=n/7*2,mx=n/7*2+min(2,n%7);
    cout<<mn<<' '<<mx<<'\n';
    return 0;
}