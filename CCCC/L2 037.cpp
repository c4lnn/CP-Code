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
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
string s[105];
char ss[105];
int p[105],top;
vector<char> res;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m,S;cin>>n>>m>>S;
    for(int i=1;i<=n;i++) cin>>s[i];
    int o;
    while(cin>>o) {
        if(o<0) break;
        if(o>0&&o<=n) {
            if(p[o]<m&&top==S) res.PB(ss[top--]);
            if(p[o]<m) ss[++top]=s[o][p[o]++];
        }
        else if(o==0){
            if(top>=1) res.PB(ss[top--]);
        }
    }
    for(int i=0;i<SZ(res);i++) cout<<res[i];
    cout<<'\n';
    return 0;
}