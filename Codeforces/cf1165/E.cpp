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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const LL MOD=998244353;
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<LL> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        a[i]=a[i]*(i+1)*(n-i);
    }
    sort(ALL(a));
    for(int i=0;i<n;i++) cin>>b[i];
    sort(ALL(b),greater<LL>());
    LL res=0;
    for(int i=0;i<n;i++) res=(res+a[i]%MOD*b[i]%MOD)%MOD;
    cout<<res<<'\n';
    return 0;
}