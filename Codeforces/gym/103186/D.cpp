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
const int N=5e3+5;
int cnt,a[N],tot[N];
LL dp[N][N],fac[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    for(int i=1;i<=n;i++) {
        int x;cin>>x;
        if(!tot[x]) a[++cnt]=x;
        ++tot[x];
    }
    sort(a+1,a+1+cnt);
    fac[0]=1;
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%MOD;
    int sum=0;
    dp[0][0]=1;
    for(int i=1;i<=cnt;i++) {
        int lim1=min(sum,n/2);
        for(int j=(sum+1)/2;j<=lim1;j++) { // 之前第一排人数
            int lim2=min(j+tot[a[i]],n/2);
            for(int k=j;k<=lim2;k++) { // 当前第一排人数
                int sec=sum+tot[a[i]]-k;
                if(sec<=k) {
                    dp[i][k]=(dp[i][k]+dp[i-1][j]*fac[tot[a[i]]]%MOD)%MOD;
                }
            }
        }
        sum+=tot[a[i]];
    }
    cout<<dp[cnt][n/2]<<'\n';
    return 0;
}