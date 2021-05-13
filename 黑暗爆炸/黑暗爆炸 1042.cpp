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
const int N=100005;
LL dp[N],res;
int c[5],d[5];
void dfs(int cnt,int pos,int sum,int t) {
    if(sum<0||cnt<0) return;
    if(pos==5) {
        if(!cnt) {
            if(t) res-=dp[sum];
            else res+=dp[sum];
        }
        return;
    }
    dfs(cnt-1,pos+1,sum-(d[pos]+1)*c[pos],t);
    dfs(cnt,pos+1,sum,t);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i=1;i<=4;i++) cin>>c[i];
    dp[0]=1;
    for(int i=1;i<=4;i++)
        for(int j=c[i];j<=100000;j++)
            dp[j]+=dp[j-c[i]];
    int T;cin>>T;
    while(T--) {
        for(int i=1;i<=4;i++) cin>>d[i];
        int s;cin>>s;
        res=dp[s];
        for(int i=1;i<=4;i++) dfs(i,1,s,i&1);
        cout<<res<<'\n';
    }
    return 0;
}