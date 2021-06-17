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
int mn[N];
VI p;
void prime_seive(int n) {
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>n) break;
            mn[i*x]=x;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prime_seive(1e5);
    int T;cin>>T;
    while(T--) {
        int a,b,k;cin>>a>>b>>k;
        if(k==1&&(__gcd(a,b)!=min(a,b)||a==b)) {
            cout<<"NO"<<'\n';
            continue;
        }
        int cnt1=0,cnt2=0;
        for(auto x:p) {
            if(x*x>a) break;
            while(a%x==0) a/=x,++cnt1;
        }
        if(a>1) ++cnt1;
        for(auto x:p) {
            if(x*x>b) break;
            while(b%x==0) b/=x,++cnt2;
        }
        if(b>1) ++cnt2;
        cout<<(cnt1+cnt2>=k?"YES":"NO")<<'\n';
    }
    return 0;
}