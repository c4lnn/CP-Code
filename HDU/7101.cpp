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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n;cin>>n;
        vector<string> s(n);
        vector<bool> vis(26);
        VI cnt(26),pos(n);
        for(int i=0;i<n;i++) cin>>s[i];
        int tot=0,lcm=1;
        for(int i=0;i<n;i++) {
            lcm=lcm*SZ(s[i])/__gcd(lcm,SZ(s[i]));
            for(auto x:s[i]) if(!vis[x-'a']) {
                vis[x-'a']=true;
                ++tot;
            }
        }
        int l=0,r=-1,res=INT_MAX;
        VI a;
        for(int i=0,t1=0,t=0;i<lcm*2*n;i++) {
            int x=s[t1][pos[t1]]-'a';
            a.PB(x);
            ++r;
            pos[t1]=(pos[t1]+1)%SZ(s[t1]),t1=(t1+1)%n;
            ++cnt[x];
            if(cnt[x]==1) ++t;
            while(cnt[a[l]]>1) --cnt[a[l]],++l;
            if(t==tot) {
                res=min(res,r-l+1);
                --cnt[a[l]];
                if(cnt[a[l]]==0) --t;
                ++l;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}