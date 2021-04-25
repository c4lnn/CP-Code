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
const int N=5e4+5;
int a[N],st[20][N];
map<int,int> mp;
void init(int n) {
    int t=log2(n);
    for(int i=1;i<=n;i++) st[0][i]=mp[a[i]];
    for(int i=1;i<=t;i++)
        for(int j=1;j<=n;j++)
            st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
}
int query(int l,int r) {
    int t=log2(r-l+1);
    return max(st[t][l],st[t][r-(1<<t)+1]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int y,r;cin>>y>>r;
        mp[y]=r;
        a[i]=y;
    }
    init(n);
    int q;cin>>q;
    for(int i=1;i<=q;i++) {
        int l,r;cin>>l>>r;
        int ll=upper_bound(a+1,a+1+n,l)-a;
        int rr=lower_bound(a+1,a+1+n,r)-a-1;
        if(!mp.count(r)&&!mp.count(l)||ll==n+1) cout<<"maybe"<<'\n';
        else if(!mp.count(l)) {
            if(rr<ll||query(ll,rr)<mp[r]) cout<<"maybe"<<'\n';
            else cout<<"false"<<'\n';
        }
        else if(!mp.count(r)) {
            if(rr<ll||query(ll,rr)<mp[l]) cout<<"maybe"<<'\n';
            else cout<<"false"<<'\n';
        }
        else {
            if(mp[l]<mp[r]) cout<<"false"<<'\n';
            else if(rr<ll||query(ll,rr)<mp[r]&&query(ll,rr)<mp[l]) {
                if(rr<ll&&r==l+1||rr+1-(ll-1)==r-l) cout<<"true"<<'\n';
                else cout<<"maybe"<<'\n';
            }
            else cout<<"false"<<'\n';
        }
    }
    return 0;
}