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
int a[20005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int mx=INT_MIN;
    for(int i=1;i<=n;i++) {
        if(n%i) continue;
        if(n/i<3) break;
        for(int j=1;j<=i;j++) {
            int sum=0;
            for(int k=j;k<=n;k+=i) sum+=a[k];
            mx=max(mx,sum);
        }
    }
    cout<<mx<<'\n';
    return 0;
}