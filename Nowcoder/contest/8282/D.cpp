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
int mn[N],mu[N];
VI p;
unordered_map<int,int> sum[N];
void get_mu(int n) {
    mu[1]=1;
    for(int i=2;i<=n;i++) {
        if(!mn[i]) mn[i]=i,mu[i]=-1,p.PB(i);
        for(auto x:p) {
            if(x*i>n) break;
            mn[x*i]=x;
            if(i%x==0) {mu[x*i]=0;break;}
            mu[x*i]=-mu[i];
        }
    }
}
void init(int n) {
    for(int i=1;i<=n;i++) sum[i][i]=mu[i];
    for(int i=1;i<=n;i++) {
        for(int j=i+i;j<=n;j+=i) {
            sum[i][j]=sum[i][j-i]+mu[j];
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    get_mu(5e4);
    init(5e4);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        int res=0;
        for(int i=1;i<=n;i++) res+=mu[i]*sum[i][n/i*i]*sum[i][n/i*i];
        cout<<res<<'\n';
    }
    return 0;
}