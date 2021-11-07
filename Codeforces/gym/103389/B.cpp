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
const int N=2e5+5;
int nxt[N][26],pos[26],f[N][20];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;cin>>m>>n;
    string s;cin>>s;
    fill(pos,pos+26,SZ(s)+1);
    for(int i=0;i<=18;i++) f[SZ(s)+1][i]=SZ(s)+1;
    for(int i=SZ(s)-1;~i;i--) {
        for(int j=0;j<m;j++) {
            f[i+1][0]=max(f[i+1][0],pos[j]);
        }
        pos[s[i]-'a']=i+1;
    }
    for(int i=0;i<m;i++) f[0][0]=max(f[0][0],pos[i]);
    for(int i=SZ(s);~i;i--) {
        for(int j=1;j<=18;j++) {
            f[i][j]=max(f[i][j],f[f[i][j-1]][j-1]);
        }
    }
    int q;cin>>q;
    while(q--) {
        int l,r;cin>>l>>r;
        int res=0;
        --l;
        for(int i=18;~i;i--) if(f[l][i]<=r) {
            l=f[l][i];
            res|=1<<i;
        }
        cout<<res+1<<'\n';
    }
    return 0;
}