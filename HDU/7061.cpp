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
const int N=1e7+5;
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
    prime_seive(1e7);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        int res=0;
        bool f=false;
        for(int i=1;i<=n;i++) {
            int x;cin>>x;
            if(n==1) {
                if(x==1) cout<<"Bob"<<'\n';
                else cout<<"Alice"<<'\n';
                f=true;
                break;
            }
            int cnt=0;
            for(int j=0;j<SZ(p);j++) {
                if(p[j]*p[j]>x) break;
                if(x%p[j]==0) {
                    while(x%p[j]==0) ++cnt,x/=p[j];
                }
            }
            if(x>1) ++cnt;
            res^=cnt;
        }
        if(!f) cout<<(res?"Alice":"Bob")<<'\n';
    }
    return 0;
}