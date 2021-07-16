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
LL exgcd(LL a,LL b,LL &x,LL &y) {
    if(!b) {x=1,y=0;return a;}
    LL ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        LL a,b,p;
        cin>>a>>b>>p;
        LL k1=p-a,k2=p-b,x,y;
        if(!a&&!b) cout<<0<<' '<<0<<' '<<0<<'\n';
        else {
            exgcd(p,k2,x,y);
            x=(x%k2+k2)%k2;
            if(!x) x+=k2;
            x*=1+a;
            k1=x*p-a;
            cout<<p-1<<' '<<k1*(p-1)<<' '<<k2*(p-1)<<'\n';
        }
    }
    return 0;
}