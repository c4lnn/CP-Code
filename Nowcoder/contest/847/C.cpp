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
const int N=1e5+5;
int b[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    if(n&1) cout<<(n==1?0:-1)<<'\n';
    else {
        VI a;
        a.PB(0);
        for(int i=1;i<n;i++) {
            if(i&1) a.PB((a[i-1]+i)%n);
            else a.PB((a[i-1]+n-i)%n);
        }
        for(int i=0;i<n-1;i++) {
            b[a[i]]=((a[i+1]-a[i])%n+n)%n;
        }
        for(int i=0;i<n;i++) cout<<b[i]<<" \n"[i==n-1];
    }
    return 0;
}