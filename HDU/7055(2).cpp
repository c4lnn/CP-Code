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
const LL MOD=998244353;
const int N=1e5+5;
VI pos[30];
LL len[N],sum[N],diff[N],dif[N],ans[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        string s;cin>>s;
        for(int i=0;i<26;i++) pos[i].clear();
        for(int i=0;i<SZ(s);i++) {
            int x=s[i]-'a';
            pos[x].PB(i);
        }
        LL res=0;
        for(int i=0;i<26;i++) if(SZ(pos[i])) {
            for(int j=1;j<SZ(pos[i]);j++) len[j]=pos[i][j]-pos[i][j-1];
            len[SZ(pos[i])]=SZ(s)-pos[i][SZ(pos[i])-1];
            for(int j=1;j<=SZ(pos[i]);j++) sum[j]=(sum[j-1]+len[j])%MOD;
            for(int j=1;j<=SZ(pos[i]);j++) diff[j]=(2*((sum[SZ(pos[i])]-sum[j]+MOD)%MOD)%MOD+2*len[j]%MOD+len[j-1])%MOD;
            dif[1]=-len[1];
            for(int j=2;j<=SZ(pos[i]);j++) dif[1]=(dif[1]+(len[j]*(-2*j+1)%MOD+MOD)%MOD)%MOD;
            for(int j=2;j<=SZ(pos[i]);j++) dif[j]=(diff[j]+dif[j-1])%MOD;
            ans[0]=0;
            for(int j=1;j<=SZ(pos[i]);j++) ans[0]=(ans[0]+len[j]*j%MOD*j%MOD)%MOD;
            for(int j=1;j<SZ(pos[i]);j++) ans[j]=(dif[j]+ans[j-1])%MOD;
            len[0]=pos[i][0]+1;
            for(int j=0;j<SZ(pos[i]);j++) res=(res+ans[j]*len[j]%MOD)%MOD;
            len[0]=0;
        }
        cout<<res<<'\n';
    }
    return 0;
}