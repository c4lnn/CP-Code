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
const int N=1e5+5;
int n;
vector<LL> a,b;
LL c[N];
bool check() {
    sort(ALL(a));
    for(int i=1;i<n<<1;i+=2) {
        if(a[i]!=a[i-1]) return false;
        b.PB(a[i]);
    }
    for(int i=1;i<n;i++) {
        if(b[i-1]==b[i]||(b[i]-b[i-1])%(2*i)) return false;
        c[i]=(b[i]-b[i-1])/(2*i);
    }
    LL sum=0,t=0;
    for(int i=1;i<n;i++) t+=c[i],sum+=t;
    t=0;
    for(int i=n-1;i>=1;i--) t+=c[i],sum+=t;
    sum+=n*t;
    if(sum>=b[n-1]||(b[n-1]-sum)%(2*n)) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while(T--) {
        cin>>n;
        a.clear();
        b.clear();
        for(int i=0;i<n<<1;i++) {
            LL x;
            cin>>x;
            a.PB(x);
        }
        cout<<(check()?"YES":"NO")<<'\n';
    }
    return 0;
}