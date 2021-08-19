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
        string t;cin>>t;
        VI cnt(26);
        string order;
        for(int i=SZ(t)-1;~i;i--) if(++cnt[t[i]-'a']==1) order.PB(t[i]);
        reverse(ALL(order));
        int sum=0,f=0;
        for(int i=0;i<SZ(order);i++) {
            if(cnt[order[i]-'a']%(i+1)) {f=-1;break;}
            sum+=cnt[order[i]-'a']/(i+1);
        }
        if(f==-1) cout<<f<<'\n';
        else {
            string s=string(t.begin(),t.begin()+sum),temp=s;
            for(auto c:order) {
                string ss;
                for(auto x:s) if(x!=c) ss+=x;
                temp+=ss;
                s=ss;
            }
            if(temp==t) cout<<string(t.begin(),t.begin()+sum)<<' '<<order<<'\n';
            else cout<<-1<<'\n';
        }
    }
    return 0;
}