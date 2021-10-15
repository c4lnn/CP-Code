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
typedef vector<LL> VLL;
typedef vector<PII> VPII;
// head
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,m;cin>>n>>m;
        VLL a(n+1),sum(n+1);
        bool f=false;
        unordered_map<LL,int> vis;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            sum[i]=sum[i-1]+a[i];
            if(!vis.count(sum[i])) vis[sum[i]]=i;
        }
        if(sum[n]==0) {
            while(m--) {
                LL x;cin>>x;
                if(x==0) cout<<0<<'\n';
                else if(vis.count(x)) cout<<vis[x]<<'\n';
                else cout<<-1<<'\n';
            }
        }
        else {
            unordered_map<LL,map<LL,int>> mp;
            if(sum[n]<0) {
                for(int i=1;i<=n;i++) sum[i]=-sum[i];
                f=true;
            }
            for(int i=n;i>=1;i--) {
                LL rem=(sum[i]%sum[n]+sum[n])%sum[n];
                mp[rem][sum[i]]=i;
            }
            while(m--) {
                LL x;cin>>x;
                if(f) x=-x;
                LL rem=(x%sum[n]+sum[n])%sum[n];
                if(x==0) cout<<0<<'\n';
                else if(!mp.count(rem)) cout<<-1<<'\n';
                else {
                    auto pos=mp[rem].upper_bound(x);
                    if(pos==mp[rem].begin()) cout<<-1<<'\n';
                    else {
                        --pos;
                        cout<<pos->second+(x-pos->first)/sum[n]*n<<'\n';
                    }
                }
            }
        }
    }
    return 0;
}