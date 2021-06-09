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
const int N=1e6+5;
int temp[26],nxt[N][26];
char s[N],t[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>n>>m>>s+1>>t+1;
    memset(temp,0x3f,sizeof temp);
    for(int i=n;~i;i--) {
        for(int j=0;j<26;j++) {
            nxt[i][j]=temp[j];
        }
        if(i>0) temp[s[i]-'a']=i;
    }
    int pos=0,res=-1;
    for(int i=1;i<=m;i++) {
        for(int j=t[i]-'a'+1;j<26;j++) if(nxt[pos][j]<=n) {
            res=max(res,i+n-nxt[pos][j]);
        }
        pos=nxt[pos][t[i]-'a'];
        if(pos==0x3f3f3f3f) return cout<<res<<'\n',0;
    }
    if(pos!=n) res=max(res,m+n-pos);
    cout<<res<<'\n';
    return 0;
}