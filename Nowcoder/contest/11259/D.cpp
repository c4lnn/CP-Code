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
int n,a[N],b[N];
bool check(int x,int d) {
    for(int i=2;i<=n;i++) {
        int t1=(a[i]>>x)&1,t2=(b[i]>>x)&1;
        if(!d&&!t1&&!t2) d=0;
        else if(d&&t1&&t2) d=1;
        else if(t1&&!t2) d^=1;
        else return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=2;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) cin>>b[i];
    for(int i=2;i<=n;i++) {
        b[i]-=a[i];
        if(b[i]<0) return cout<<0<<'\n',0;
    }
    LL res=1;
    for(int i=0;i<31;i++) {
        int t1=check(i,0),t2=check(i,1);
        if(!t1&&!t2) return cout<<0<<'\n',0;
        else if(t1&&t2) res<<=1;
    }
    cout<<res<<'\n';
    return 0;
}