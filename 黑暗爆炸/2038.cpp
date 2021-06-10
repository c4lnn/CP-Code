#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e4+5;
int n,m,c[N],pos[N];
ll sum[N];
struct node {
    int l,r;
    ll a,b;
    int id;
}ask[N];
bool cmp1(node a,node b) {
    return pos[a.l]==pos[b.l]?a.r<b.r:a.l<b.l;
}
bool cmp2(node a,node b) {
    return a.id<b.id;
}
ll gcd(ll a,ll b) {
    return b?gcd(b,a%b):a;
}
void solve() {
    int l=1,r=0;
    ll a=0,b=0;
    for(int i=1;i<=m;i++) {
        b=(ll)(ask[i].r-ask[i].l+1)*(ask[i].r-ask[i].l)/2;
        while(l>ask[i].l) l--,sum[c[l]]++,a+=sum[c[l]]*(sum[c[l]]-1)/2-(sum[c[l]]-1)*(sum[c[l]]-2)/2;
        while(l<ask[i].l) sum[c[l]]--,a+=sum[c[l]]*(sum[c[l]]-1)/2-(sum[c[l]]+1)*sum[c[l]]/2,l++;
        while(r>ask[i].r) sum[c[r]]--,a+=sum[c[r]]*(sum[c[r]]-1)/2-(sum[c[r]]+1)*sum[c[r]]/2,r--;
        while(r<ask[i].r) r++,sum[c[r]]++,a+=sum[c[r]]*(sum[c[r]]-1)/2-(sum[c[r]]-1)*(sum[c[r]]-2)/2;
        if(ask[i].l==ask[i].r) {ask[i].a=0,ask[i].b=1;continue;}
        ll GCD=gcd(a,b);
        ask[i].a=a/GCD,ask[i].b=b/GCD;
    }
    sort(ask+1,ask+1+m,cmp2);
    for(int i=1;i<=m;i++) cout<<ask[i].a<<"/"<<ask[i].b<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int t=sqrt(n);
    for(int i=1;i<=n;i++) cin>>c[i],pos[i]=i/t+1;
    for(int i=1;i<=m;i++) cin>>ask[i].l>>ask[i].r,ask[i].id=i;
    sort(ask+1,ask+1+m,cmp1);
    solve();
    return 0;
}