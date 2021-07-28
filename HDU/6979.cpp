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
int o[N],r[N],g[N],b[N],sr[N],sg[N],sb[N],pre[N];
int get(char a,char b) {
    int ret=0;
    if(isdigit(a)) ret=a-'0';
    else ret=a-'A'+10;
    ret*=16;
    if(isdigit(b)) ret+=b-'0';
    else ret+=b-'A'+10;
    return ret;
}
void inv(int x) {
    int t=x/16;
    if(t<10) cout<<t;
    else cout<<char('A'+t-10);
    t=x%16;
    if(t<10) cout<<t;
    else cout<<char('A'+t-10);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        int n,q;cin>>n>>q;
        for(int i=1;i<=n;i++) {
            cin>>o[i];
            string s;cin>>s;
            r[i]=get(s[0],s[1]);
            g[i]=get(s[2],s[3]);
            b[i]=get(s[4],s[5]);
        }
        for(int i=1;i<=n;i++) {
            sr[i]=sr[i-1]+r[i];
            sg[i]=sg[i-1]+g[i];
            sb[i]=sb[i-1]+b[i];
        }
        int t=0;
        for(int i=1;i<=n;i++) {
            if(o[i]==1) t=i;
            pre[i]=t;
        }
        for(int i=1;i<=q;i++) {
            int L,R;cin>>L>>R;
            int t=pre[R]>=L?pre[R]:0;
            inv(min(r[t]+sr[R]-sr[t>=L?t:L-1],255));
            inv(min(g[t]+sg[R]-sg[t>=L?t:L-1],255));
            inv(min(b[t]+sb[R]-sb[t>=L?t:L-1],255));
            cout<<'\n';
        }
    }
    return 0;
}