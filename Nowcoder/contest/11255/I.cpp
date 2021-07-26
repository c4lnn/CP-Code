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
const int N=2e5+5;
int n,a[N],b[N],c[N];
bool st[N];
void update(int x,int v) {
    for(int i=x;i<=n;i+=i&-i) b[i]+=v;
}
int query(int l,int r) {
    int ret=0;
    for(int i=r;i;i-=i&-i) ret+=b[i];
    for(int i=l-1;i;i-=i&-i) ret-=b[i];
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        c[i]=query(a[i]+1,n);
        update(a[i],1);
    }
    LL res=0;
    for(int i=1;i<=n;i++) {
        if(st[a[i]+1]) {
            st[a[i]]=false;
            --res;
        }
        else st[a[i]]=true;
    }
    for(int i=1;i<=n;i++) {
        res+=c[i];
    }
    cout<<res<<'\n';
    return 0;
}