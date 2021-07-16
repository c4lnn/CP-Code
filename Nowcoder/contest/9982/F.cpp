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
//head
const int N=1e5+5;
int n,a[N],id[N],q[N<<1],l=N+1,r=N,rev;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],id[a[i]]=i;
    int k=0;
    for(int i=1;i<=n;i++) if(id[i]!=i) {k=id[i]-i+1;break;}
    if(k) {
        for(int i=1;i<=k;i++) q[++r]=a[i];
        for(int i=1;i<=n;i++) {
            if(q[rev?r:l]!=i&&abs(r-l)+1==k) rev^=1;
            if(q[rev?r:l]!=i) return cout<<"no"<<'\n',0;
            rev?--r:++l;
            if(i+k<=n) rev?q[--l]=a[i+k]:q[++r]=a[i+k];
        }
    }
    else k=1;
    cout<<"yes"<<'\n';
    cout<<k<<'\n';
    return 0;
}