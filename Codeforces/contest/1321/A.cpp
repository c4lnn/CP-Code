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
const int N=105;
int a[N],b[N],tot1,tot2,n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        if(a[i]==1&&b[i]==0) ++tot1;
        else if(a[i]==0&&b[i]==1) ++tot2;
    }
    if(!tot1) cout<<-1<<'\n';
    else cout<<(tot2+tot1)/tot1<<'\n';
    return 0;
}