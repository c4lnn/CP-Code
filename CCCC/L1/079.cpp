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
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
int tot[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    int mn=0x3f3f3f3f,mx=0;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        tot[x]++;
        mn=min(mn,x);
        mx=max(mx,x);
    }
    cout<<mn<<' '<<tot[mn]<<'\n';
    cout<<mx<<' '<<tot[mx]<<'\n';
    return 0;
}