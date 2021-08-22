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
int b[N],tot[N];
map<PII,int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        int cnt=0;
        mp.clear();
        for(int i=1;i<=n;i++) {
            int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
            x1-=x2,y1-=y2;
            if(x1<0) x1=-x1,y1=-y1;
            int d=__gcd(x1,y1);
            x1/=d,y1/=d;
            if(!mp.count(MP(x1,y1))) mp[MP(x1,y1)]=++cnt,tot[cnt]=0;
            ++tot[mp[MP(x1,y1)]];
        }
        for(int i=1;i<=100000;i++) b[i]=0;
        for(int i=1;i<=cnt;i++) ++b[tot[i]];
        for(int i=100000;i;i--) b[i]+=b[i+1];
        for(int i=1,t=0,r=0;i<=n;i++) {
            while(i>r) ++t,r+=b[t];
            cout<<i-t<<'\n';
        }
    }
    return 0;
}