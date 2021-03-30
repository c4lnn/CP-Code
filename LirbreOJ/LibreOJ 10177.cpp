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
//head
const int N=1e5+5;
LL s[N],dp[N][2];
int main() {
    //freopen("E:/OneDrive/IO/in.txt","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    deque<int> dq;
    dq.push_back(0);
    for(int i=1;i<=n;i++) {
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
        if(SZ(dq)&&dq.front()<i-m) dq.pop_front();
        dp[i][1]=s[i]+dp[dq.front()][0]-s[dq.front()];
        while(SZ(dq)&&dp[dq.back()][0]-s[dq.back()]<=dp[i][0]-s[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout<<max(dp[n][0],dp[n][1])<<'\n';
    return 0;
}