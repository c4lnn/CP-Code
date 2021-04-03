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
const LL P[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
const int N=1500000;
LL dp[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    LL a,b;
    cin>>a>>b;
    dp[0]=1;
    for(LL i=a;i<=b;i++) {
        int bit=0;
        for(int j=0;j<20;j++) if(i%P[j]==0) bit|=1<<j;
        for(int j=0;j<1<<20;j++) {
            if(bit&j) continue;
            dp[bit|j]+=dp[j];
        }
    }
    LL res=0;
    for(int i=0;i<1<<20;i++) res+=dp[i];
    cout<<res<<'\n';
    return 0;
}