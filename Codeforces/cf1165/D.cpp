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
const int N=1e6+5;
int mn[N];
VI p;
void get_prime() {
    for(int i=2;i<=1000000;i++) {
        if(!mn[i]) mn[i]=i,p.PB(i);
        for(auto x:p) {
            if(x>mn[i]||x*i>1000000) break;
            mn[x*i]=x;
        }
    }
}
int get_factor(LL n) {
    int ret=1;
    for(auto x:p) {
        if(1ll*x*x>n) break;
        if(n%x==0) {
            int tot=0;
            while(n%x==0) n/=x,++tot;
            ret*=tot+1;
        }
    }
    if(n>1) ret*=2;
    return ret;
}
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_prime();
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        vector<LL> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        sort(ALL(a));
        bool f=true;
        LL t=a[0]*a[n-1];
        for(int i=1;i<(n+1)>>1;i++) {
            if(a[i]*a[n-1-i]!=t) {
                f=false;
                break;
            }
        }
        if(f&&get_factor(t)!=n+2) f=false;
        cout<<(f?t:-1)<<'\n';
    }
    return 0;
}