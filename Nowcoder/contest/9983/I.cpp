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
const int N=1e6+5;
int a[N],pre[N],t[N],dp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,0xc0,sizeof dp);
    for(int i=n;i>=1;i--) {
        pre[t[a[i]]]=i;
        t[a[i]]=i;
    }
    dp[1]=0;
    int mx=0;
    for(int i=2;i<=n;i++) {
        dp[i]=max(dp[i-1],dp[pre[i]]+1);
        mx=max(dp[i],mx);
    }
    cout<<mx<<'\n';
    return 0;
}