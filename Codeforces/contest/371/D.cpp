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
int fa[N];
LL a[N],b[N];
int find(int x) {
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    int fx=find(x),fy=find(y);
    fa[fx]=fy;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    a[n+1]=1e18;
    for(int i=1;i<=n+1;i++) fa[i]=i;
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int o;cin>>o;
        if(o==1) {
            int x,v;cin>>x>>v;
            while(v) {
                x=find(x);
                int t=min(v*1ll,a[x]-b[x]);
                b[x]+=t;
                v-=t;
                if(b[x]==a[x]) merge(x,x+1);
            }
        }
        else {
            int x;cin>>x;
            cout<<b[x]<<'\n';
        }
    }
    return 0;
}