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
int cnt[N][26],sum[26];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;cin>>T;
    while(T--) {
    int n,m;cin>>n>>m;
        string s;cin>>s;
        ++cnt[0][s[0]-'a'];
        for(int i=1;i<n;i++) {
            for(int j=0;j<26;j++) {
                cnt[i][j]=cnt[i-1][j];
            }
            ++cnt[i][s[i]-'a'];
        }
        memset(sum,0,sizeof sum);
        for(int i=1;i<=m;i++) {
            int x;cin>>x;
            --x;
            for(int j=0;j<26;j++) {
                sum[j]+=cnt[x][j];
            }
        }
        for(int i=0;i<26;i++) cout<<sum[i]+cnt[n-1][i]<<" \n"[i==25];
        cnt[0][s[0]-'a']=0;
    }
    return 0;
}