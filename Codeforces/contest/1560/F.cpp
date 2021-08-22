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
int bit[20],mn[20],d[20];
int solve(int n,int k) {
    int t=n;
    VI a;
    while(t) a.PB(t%10),t/=10;
    a.PB(10);
    reverse(ALL(a));
    mn[0]=10;
    int pos=-1;
    for(int i=1;i<SZ(a);i++) {
        int x=a[i];
        bit[i]=bit[i-1]|(1<<x);
        d[i]=d[i-1]*10+x;
        mn[i]=min(mn[i-1],x);
        if(__builtin_popcount(bit[i])>k) {pos=i;break;}
    }
    if(pos==-1) return n;
    for(int i=pos;i;i--) {
        int x=a[i],now=0;
        if(x==9) continue;
        if(__builtin_popcount(bit[i-1])==k) {
            for(int j=x+1;j<=9;j++) if(bit[i-1]&(1<<j)) {
                now=d[i-1]*10+j;
                while(now<n) now=now*10+mn[i-1];
                return now;
            }
        }
        else {
            now=d[i-1]*10+x+1;
            if(__builtin_popcount(bit[i-1]|((1<<(x+1))+1))<=k) {
                while(now<n) now=now*10;
                return now;
            }
            else {
                while(now<n) now=now*10+min(x+1,mn[i-1]);
                return now;
            }
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,k;cin>>n>>k;
        cout<<solve(n,k)<<'\n';
    }
    return 0;
}