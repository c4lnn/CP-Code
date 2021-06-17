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
const int N=2e5+5;
int n,m,k[N],sum;
bool st[N];
PII o[N];
bool check(int x) {
    for(int i=1;i<=n;i++) st[i]=false;
    int tot=0,pre=0x3f3f3f3f;
    for(int i=m;i>=1;i--) {
        if(o[i].FI>x||st[o[i].SE]) continue;
        pre=min(pre,o[i].FI);
        int t=min(pre,k[o[i].SE]);
        tot+=t;
        st[o[i].SE]=true;
        pre-=t;
    }
    return tot+(sum-tot)*2<=x;
}
int solve() {
    sort(o+1,o+1+m);
    int l=0,r=sum*2;
    while(l<r) {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>k[i],sum+=k[i];
    for(int i=1;i<=m;i++) cin>>o[i].FI>>o[i].SE;
    cout<<solve()<<'\n';
    return 0;
}