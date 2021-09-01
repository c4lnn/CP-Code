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
int a[N],sum[N<<1];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,k;cin>>n>>k;
        PII res=MP(0,n+k);
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=n+1;i<n+k;i++) sum[i]=sum[i-1]+a[i-n];
        deque<int> q;
        for(int i=1;i<n+k;i++) {
            while(SZ(q)&&i-q.front()>k) q.pop_front();
            while(SZ(q)&&sum[i-1]<sum[q.back()]) q.pop_back();
            q.PB(i-1);
            if(res.SE==n+k||sum[i]-sum[q.front()]>sum[res.SE]-sum[res.FI-1]) res=MP(q.front()+1,i);
        }
        cout<<sum[res.SE]-sum[res.FI-1]<<' '<<res.FI<<' '<<(res.SE>n?res.SE-n:res.SE)<<'\n';
    }
    return 0;
}