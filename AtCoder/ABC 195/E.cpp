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
const int N=2e5+5;
int n,dp[N][7];
string s,x;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>s>>x;
    dp[n][0]=1;
    for(int i=n-1;~i;i--) {
        for(int j=0;j<7;j++) {
            int a=dp[i+1][(j*3+s[i]-'0')%7],b=dp[i+1][j*3%7];
            if(x[i]=='T') dp[i][j]=a|b;
            else dp[i][j]=a&b;
        }
    }
    cout<<(dp[0][0]?"Takahashi":"Aoki")<<'\n';
    return 0;
}