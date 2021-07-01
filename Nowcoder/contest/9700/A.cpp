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
//head
const int N=1e5+5;
int n,a[N];
bool solve() {
    bool f=false;
    for(int i=3;i<=n;i++) if(a[i]-a[i-1]!=a[2]-a[1]) f=true;
    if(!f) return true;
    f=false;
    for(int i=3;i<=n;i++) if(1.0*a[i]/a[i-1]!=1.0*a[2]/a[1]) f=true;
    if(!f) return true;
    f=false;
    for(int i=3;i<=n;i++) if(a[i]%a[i-1]!=a[2]%a[1]) f=true;
    if(!f) return true;
    return false;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    puts(solve()?"YES":"NO");
    return 0;
}