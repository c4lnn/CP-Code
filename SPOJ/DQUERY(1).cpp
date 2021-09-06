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
const int N=3e4+5;
const int M=1e6+5;
int pre[M],rt[N],ls[N<<5],rs[N<<5],w[N<<5],cnt;
void update(int &p,int q,int L,int R,int x,int v) {
    p=++cnt;
    ls[p]=ls[q],rs[p]=rs[q],w[p]=w[q]+v;
    if(L==R) return;
    int mid=L+R>>1;
    if(x<=mid) update(ls[p],ls[q],L,mid,x,v);
    else update(rs[p],rs[q],mid+1,R,x,v);
}
int query(int p,int L,int R,int l,int r) {
    if(L>=l&&R<=r) return w[p];
    int mid=L+R>>1;
    if(r<=mid) return query(ls[p],L,mid,l,r);
    if(l>mid) return query(rs[p],mid+1,R,l,r);
    return query(ls[p],L,mid,l,mid)+query(rs[p],mid+1,R,mid+1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        if(!pre[x]) update(rt[i],rt[i-1],1,n,i,1);
        else {
            int t;
            update(t,rt[i-1],1,n,pre[x],-1);
            update(rt[i],t,1,n,i,1);
        }
        pre[x]=i;
    }
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int l,r;cin>>l>>r;
        cout<<query(rt[r],1,n,l,r)<<'\n';
    }
    return 0;
}