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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
        string s;
        cin>>s;
        VI pos[26];
        for(int i=0;i<SZ(s);i++) {
            int x=s[i]-'a';
            pos[x].PB(i);
        }
        LL res=0;
        for(int i=0;i<26;i++) if(SZ(pos[i])) {
            LL sum1=0,sum2=0;
            for(int j=0;j<SZ(pos[i]);j++) {
                sum1=(sum1+((j==SZ(pos[i])-1?SZ(s):pos[i][j+1])-pos[i][j])*(j+1)%MOD*(j+1)%MOD)%MOD;
                sum2=(sum2+((j==SZ(pos[i])-1?SZ(s):pos[i][j+1])-pos[i][j])*(j+1)%MOD)%MOD;
            }
            sum1=sum1*(SZ(s)+1)%MOD;
            sum2=sum2*sum2%MOD;
            res=(res+sum1-sum2+MOD)%MOD;
        }
        cout<<res<<'\n';
    }
    return 0;
}