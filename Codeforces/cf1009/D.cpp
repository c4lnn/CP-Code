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
int n,m;
LL mn[N],phi[N],a[N];
vector<LL> p;
void get_phi(LL n) {
    phi[1]=1;
    for(LL i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i),phi[i]=i-1;
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
            phi[i*x]=i%x?phi[i]*(x-1):phi[i]*x;
        }
    }
    for(int i=2;i<=n;i++) a[i]=a[i-1]+phi[i];
}
void print(int m) {
    cout<<"Possible"<<'\n';
    for(int i=2;i<=n;i++) {
        cout<<1<<' '<<i<<'\n';
        if(--m==0) return;
    }
    for(int i=n;i>=2;i--)
        for(int j=2;j<=i-1;j++)
            if(__gcd(i,j)==1) {
                cout<<j<<' '<<i<<'\n';
                if(--m==0) return;
            }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_phi(100000);
    cin>>n>>m;
    if(m>a[n]||m<n-1) cout<<"Impossible"<<'\n';
    else print(m);
    return 0;
}