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
        int k;string s;cin>>s>>k;
        VI cnt(26);
        int tot=0;
        LL res=0;
        for(int l=0,r=0;r<SZ(s);r++) {
            if(++cnt[s[r]-'a']==1) ++tot;
            while(l<r&&tot>k) if(--cnt[s[l++]-'a']==0) --tot;
            while(l<r&&cnt[s[l]-'a']>1) --cnt[s[l++]-'a'];
            if(tot>=k) res+=l+1;
        }
        cout<<res<<'\n';
    }
    return 0;
}