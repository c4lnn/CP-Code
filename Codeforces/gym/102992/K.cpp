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
    int n,k;cin>>n>>k;
    if(k==0) return cout<<-1<<'\n',0;
    if(k&1) {
        cout<<1<<" \n"[n==1];
        for(int i=2;i<=k;i++) cout<<(i&1?i-1:i+1)<<" \n"[i==n];
    }
    else for(int i=1;i<=k;i++) cout<<(i&1?i+1:i-1)<<" \n"[i==n];
    for(int i=k+1;i<=n;i++) cout<<i<<" \n"[i==n];
    return 0;
}